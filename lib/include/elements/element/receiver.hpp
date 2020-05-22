/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(ELEMENTS_RECEIVER_MARCH_1_2020)
#define ELEMENTS_RECEIVER_MARCH_1_2020

#include <infra/string_view.hpp>

namespace cycfi { namespace elements
{
   struct receiver_base
   {
      virtual              ~receiver_base() = default;
   };

   template <typename T>
   struct receiver : receiver_base
   {
      using receiver_type = T;
      using getter_type = T;
      using param_type = T;

      virtual void         value(param_type val) = 0;
      virtual getter_type  value() const = 0;
   };

   template <>
   struct receiver<std::string> : receiver_base
   {
      using receiver_type = std::string;
      using getter_type = std::string const&;
      using param_type = string_view;

      virtual void         value(param_type str) = 0;
      virtual getter_type  value() const = 0;
   };
}}

#endif
