//
// Copyright 2016 - 2024 (C). Alex Robenko. All rights reserved.
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <tuple>
#include <type_traits>

#include "macro_common.h"
#include "gen_enum.h"
#include "base_detection.h"

#ifdef COMMS_MUST_DEFINE_BASE
#define COMMS_ACCESS_TRANSPORT_FIELD_FUNC(T_, t_, n_) \
    typename std::tuple_element<COMMS_CONCATENATE(TransportFieldIdx_, n_), typename Base::T_>::type& COMMS_CONCATENATE(transportField_, n_)()
#define COMMS_ACCESS_TRANSPORT_FIELD_CONST_FUNC(T_, t_, n_) \
    const typename std::tuple_element<COMMS_CONCATENATE(TransportFieldIdx_, n_), typename Base::T_>::type& COMMS_CONCATENATE(transportField_, n_)() const
#define COMMS_MSG_TRANSPORT_FIELDS_ACCESS_FUNC \
    typename Base::TransportFields& transportFields()
#define COMMS_MSG_TRANSPORT_FIELDS_ACCESS_CONST_FUNC \
    const typename Base::TransportFields& transportFields() const

#else // #ifdef COMMS_MUST_DEFINE_BASE
#define COMMS_ACCESS_TRANSPORT_FIELD_FUNC(T_, t_, n_) FUNC_AUTO_REF_RETURN(COMMS_CONCATENATE(transportField_, n_), decltype(std::get<COMMS_CONCATENATE(TransportFieldIdx_, n_)>(t_)))
#define COMMS_ACCESS_TRANSPORT_FIELD_CONST_FUNC(T_, t_, n_) FUNC_AUTO_REF_RETURN_CONST(COMMS_CONCATENATE(transportField_, n_), decltype(std::get<COMMS_CONCATENATE(TransportFieldIdx_, n_)>(t_)))
#define COMMS_MSG_TRANSPORT_FIELDS_ACCESS_FUNC FUNC_AUTO_REF_RETURN(transportFields, decltype(comms::toMessage(*this).transportFields()))
#define COMMS_MSG_TRANSPORT_FIELDS_ACCESS_CONST_FUNC FUNC_AUTO_REF_RETURN_CONST(transportFields, decltype(comms::toMessage(*this).transportFields()))
#endif // #ifdef COMMS_MUST_DEFINE_BASE

#define COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_ACCESS_TRANSPORT_FIELD_FUNC(T_, t_, n_) {\
        return std::get<COMMS_CONCATENATE(TransportFieldIdx_, n_)>(t_); \
    } \
    COMMS_ACCESS_TRANSPORT_FIELD_CONST_FUNC(T_, t_, n_) {\
        return std::get<COMMS_CONCATENATE(TransportFieldIdx_, n_)>(t_); \
    }

#define COMMS_TRANSPORT_FIELD_ACC_FUNC_1(T_, t_, n_) COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_)
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_2(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_1(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_3(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_2(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_4(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_3(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_5(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_4(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_6(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_5(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_7(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_6(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_8(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_7(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_9(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_8(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_10(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_9(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_11(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_10(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_12(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_11(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_13(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_12(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_14(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_13(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_15(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_14(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_16(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_15(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_17(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_16(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_18(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_17(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_19(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_18(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_20(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_19(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_21(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_20(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_22(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_21(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_23(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_22(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_24(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_23(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_25(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_24(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_26(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_25(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_27(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_26(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_28(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_27(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_29(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_28(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_30(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_29(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_31(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_30(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_32(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_31(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_33(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_32(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_34(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_33(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_35(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_34(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_36(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_35(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_37(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_36(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_38(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_37(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_39(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_38(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_40(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_39(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_41(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_40(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_42(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_41(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_43(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_42(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_44(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_43(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_45(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_44(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_46(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_45(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_47(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_46(T_, t_, __VA_ARGS__))
#define COMMS_TRANSPORT_FIELD_ACC_FUNC_48(T_, t_, n_, ...) \
    COMMS_TRANSPORT_FIELD_ACC_FUNC(T_, t_, n_) \
    COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_47(T_, t_, __VA_ARGS__))

#define COMMS_CHOOSE_TRANSPORT_FIELD_ACC_FUNC_(N, T_, t_, ...) COMMS_EXPAND(COMMS_TRANSPORT_FIELD_ACC_FUNC_ ## N(T_, t_, __VA_ARGS__))
#define COMMS_CHOOSE_TRANSPORT_FIELD_ACC_FUNC(N, T_, t_, ...) COMMS_EXPAND(COMMS_CHOOSE_TRANSPORT_FIELD_ACC_FUNC_(N, T_, t_, __VA_ARGS__))
#define COMMS_DO_TRANSPORT_FIELD_ACC_FUNC(T_, t_, ...) \
    COMMS_EXPAND(COMMS_CHOOSE_TRANSPORT_FIELD_ACC_FUNC(COMMS_NUM_ARGS(__VA_ARGS__), T_, t_, __VA_ARGS__))

#define COMMS_DEFINE_TRANSPORT_FIELD_ENUM(...) COMMS_EXPAND(COMMS_DEFINE_ENUM(TransportFieldIdx, __VA_ARGS__));












