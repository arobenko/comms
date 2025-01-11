//
// Copyright 2017 - 2025 (C). Alex Robenko. All rights reserved.
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "comms/Assert.h"
#include "comms/ErrorStatus.h"

namespace comms
{

namespace field
{

namespace adapter
{

template <typename TLenField, comms::ErrorStatus TStatus, typename TBase>
class SequenceSerLengthFieldPrefix : public TBase
{
    using BaseImpl = TBase;
    using LenField = TLenField;

    static const std::size_t MaxAllowedLength =
            static_cast<std::size_t>(LenField::maxValue());


    static_assert(!LenField::isVersionDependent(),
            "Prefix fields must not be version dependent");

public:
    using ValueType = typename BaseImpl::ValueType;
    using ElementType = typename BaseImpl::ElementType;

    SequenceSerLengthFieldPrefix() = default;

    explicit SequenceSerLengthFieldPrefix(const ValueType& val)
      : BaseImpl(val)
    {
    }

    explicit SequenceSerLengthFieldPrefix(ValueType&& val)
      : BaseImpl(std::move(val))
    {
    }

    SequenceSerLengthFieldPrefix(const SequenceSerLengthFieldPrefix&) = default;
    SequenceSerLengthFieldPrefix(SequenceSerLengthFieldPrefix&&) = default;
    SequenceSerLengthFieldPrefix& operator=(const SequenceSerLengthFieldPrefix&) = default;
    SequenceSerLengthFieldPrefix& operator=(SequenceSerLengthFieldPrefix&&) = default;

    std::size_t length() const
    {
        auto valLength = BaseImpl::length();
        LenField lenField;
        lenField.setValue(std::min(valLength, std::size_t(MaxAllowedLength)));
        return lenField.length() + valLength;
    }

    static constexpr std::size_t minLength()
    {
        return LenField::minLength();
    }

    static constexpr std::size_t maxLength()
    {
        return LenField::maxLength() + BaseImpl::maxLength();
    }

    bool valid() const
    {
        if ((!BaseImpl::valid()) || (!canWrite())) {
            return false;
        }

        LenField lenField;
        auto lenValue = std::min(BaseImpl::length(), std::size_t(MaxAllowedLength));
        lenField.setValue(lenValue);
        return lenField.valid();
    }

    template <typename TIter>
    comms::ErrorStatus read(TIter& iter, std::size_t len)
    {
        auto fromIter = iter;
        LenField lenField;
        auto es = lenField.read(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        auto diff = static_cast<std::size_t>(std::distance(fromIter, iter));
        COMMS_ASSERT(diff <= len);
        len -= diff;
        auto remLen = static_cast<std::size_t>(lenField.getValue());
        if (len < remLen) {
            return TStatus;
        }

        es = BaseImpl::read(iter, remLen);
        if (es == comms::ErrorStatus::NotEnoughData) {
            return TStatus;
        }

        return es;
    }

    static constexpr bool hasReadNoStatus()
    {
        return false;
    }

    template <typename TIter>
    void readNoStatus(TIter& iter) = delete;

    bool canWrite() const
    {
        if (!BaseImpl::canWrite()) {
            return false;
        }

        auto len = BaseImpl::length();
        if (MaxAllowedLength < len) {
            return false;
        }

        LenField lenField;
        lenField.setValue(len);
        return lenField.canWrite();
    }

    template <typename TIter>
    comms::ErrorStatus write(TIter& iter, std::size_t len) const
    {
        if (!canWrite()) {
            return comms::ErrorStatus::InvalidMsgData;
        }

        auto lenVal = BaseImpl::length();
        LenField lenField;
        lenField.setValue(lenVal);
        auto es = lenField.write(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        COMMS_ASSERT(lenField.length() <= len);
        return BaseImpl::write(iter, lenVal);
    }

    static constexpr bool hasWriteNoStatus()
    {
        return false;
    }

    template <typename TIter>
    void writeNoStatus(TIter& iter) const = delete;
};

}  // namespace adapter

}  // namespace field

}  // namespace comms




