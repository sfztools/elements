/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <elements/support/resource_paths.hpp>
#include <infra/filesystem.hpp>
#include <infra/string_view.hpp>
#include <string>

namespace cycfi { namespace elements
{
   std::vector<fs::path> resource_paths;

   std::string find_file(string_view file)
   {
      std::string full_path;
      if (fs::path(file.data()).is_absolute())
      {
         if (fs::exists(full_path))
            full_path = std::string(file);
      }
      else
      {
         for (auto const& path : resource_paths)
         {
            fs::path target = fs::path(path) / file.data();
            if (fs::exists(target))
            {
               full_path = target.string();
               break;
            }
         }
      }
      return full_path;
   }
}}
