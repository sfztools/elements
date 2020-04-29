/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License (https://opensource.org/licenses/MIT)
=============================================================================*/
#include <elements.hpp>

using namespace cycfi::elements;

// Main window background color
auto bkd_color = rgba(62, 62, 62, 255);
auto background = box(bkd_color);
auto rbox_ = rbox(colors::gold.opacity(0.8));

auto make_vtile_aligns()
{
   auto _box = top_margin(
      { 10 },
      hsize(150, rbox_)
   );

   return margin(
      { 10, 40, 10, 10 },
      hmin_size(150,
         vtile(
            halign(0.0, _box),
            halign(0.2, _box),
            halign(0.4, _box),
            halign(0.6, _box),
            halign(0.8, _box),
            halign(1.0, _box)
         )
      )
   );
}

auto make_vtile_stretch()
{
   auto _box = top_margin(
      { 10 },
      rbox_
   );

   return margin(
      { 10, 40, 10, 10 },
      hmin_size(150,
         vtile(
            vstretch(1.0, _box),
            vstretch(0.5, _box),
            vstretch(0.5, _box),
            vstretch(0.5, _box),
            vstretch(2.0, _box)
         )
      )
   );
}

auto make_vtile_mixed()
{
   auto _box = top_margin(
      { 10 },
      rbox_
   );

   auto _box2 = top_margin(
      { 10 },
      hsize(150, rbox_)
   );

   return margin(
      { 10, 40, 10, 10 },
      hmin_size(150,
         vtile(
            halign(0.0, vsize(40.0, _box2)),
            vstretch(2.0, _box),
            vstretch(1.0, _box),
            vstretch(0.5, vmin_size(20, _box)),
            halign(1.0, vsize(40.0, _box2))
         )
      )
   );
}

auto make_htile_aligns()
{
   auto _box = left_margin(
      { 10 },
      vsize(150, rbox_)
   );

   return margin(
      { 0, 50, 10, 10 },
      htile(
         valign(0.0, _box),
         valign(0.2, _box),
         valign(0.4, _box),
         valign(0.6, _box),
         valign(0.8, _box),
         valign(1.0, _box)
      )
   );
}

auto make_htile_stretch()
{
   auto _box = left_margin(
      { 10 },
      rbox_
   );

   return margin(
      { 0, 50, 10, 10 },
      htile(
         hstretch(1.0, _box),
         hstretch(0.5, _box),
         hstretch(0.5, _box),
         hstretch(0.5, _box),
         hstretch(2.0, _box)
      )
   );
}

auto make_htile_mixed()
{
   auto _box = left_margin(
      { 10 },
      rbox_
   );

   auto _box2 = left_margin(
      { 10 },
      vsize(150, rbox_)
   );

   return margin(
      { 0, 50, 10, 10 },
      htile(
         valign(0.0, hsize(40.0, _box2)),
         hstretch(2.0, _box),
         hstretch(1.0, _box),
         hstretch(0.5, hmin_size(20, _box)),
         valign(1.0, hsize(40.0, _box2))
      )
   );
}

auto make_flow()
{
   constexpr auto line_height = 30;
   constexpr auto min_size = 10;
   constexpr auto max_width = 100;
   constexpr auto max_height = line_height;
   constexpr auto num_elements = 40;

   static auto c = flow_composite{};
   for (int i = 0; i < num_elements; ++i)
   {
      auto w = min_size + ((double(std::rand()) * (max_width - min_size)) / RAND_MAX);
      auto h = min_size + ((double(std::rand()) * (max_height - min_size)) / RAND_MAX);
      auto _box = vsize(line_height, align_bottom(margin(
         { 5, 5, 5, 5 }, fixed_size({ float(w), float(h) }, rbox_)
      )));
      c.push_back(share(_box));
   }

   auto flow_pane = margin(
      { 0, 50, 10, 10 },
      align_top(flow(c))
   );

   return margin({ 10, 10, 10, 10 },
      group("Flow Elements (randomly sized elements)", flow_pane, 0.9, false)
   );
}

auto make_vgrid()
{
   auto _box = top_margin(
      { 10 },
      hsize(150, rbox_)
   );

   // Place the grid coordinates in a plain array
   static float grid[] = { 50, 100, 150, 200, 250, 300 };

   return margin(
      { 10, 40, 10, 10 },
      hmin_size(150,
         vgrid(
            grid,
            halign(0.0, _box),
            halign(0.2, _box),
            halign(0.4, _box),
            halign(0.6, _box),
            halign(0.8, _box),
            halign(1.0, _box)
         )
      )
   );
}

auto make_hgrid()
{
   auto _box = left_margin(
      { 10 },
      vsize(150, rbox_)
   );

   // You can also place the grid coordinates a std::array
   static std::array<float, 6> grid = { 50, 100, 150, 200, 250, 300 };

   return margin(
      { 0, 50, 10, 10 },
      hgrid(
         grid,
         valign(0.0, _box),
         valign(0.2, _box),
         valign(0.4, _box),
         valign(0.6, _box),
         valign(0.8, _box),
         valign(1.0, _box)
      )
   );
}

auto make_aligns()
{
   return htile(
      margin({ 10, 10, 10, 10 },
         group("VTile with Fixed-Sized, Aligned Elements", make_vtile_aligns(), 0.9, false)
      ),
      margin({ 10, 10, 10, 10 },
         group("HTile with Fixed-Sized, Aligned Elements", make_htile_aligns(), 0.9, false)
      )
   );
}

auto make_percentages()
{
   return htile(
      margin({ 10, 10, 10, 10 },
         group("VTile with Stretchable Elements", make_vtile_stretch(), 0.9, false)
      ),
      margin({ 10, 10, 10, 10 },
         group("HTile with Stretchable Elements", make_htile_stretch(), 0.9, false)
      )
   );
}

auto make_mixed()
{
   return htile(
      margin({ 10, 10, 10, 10 },
         group("VTile Fixed-Sized and Stretchable Elements", make_vtile_mixed(), 0.9, false)
      ),
      margin({ 10, 10, 10, 10 },
         group("HTile Fixed-Sized and Stretchable Elements", make_htile_mixed(), 0.9, false)
      )
   );
}

auto make_grids()
{
   return htile(
      margin({ 10, 10, 10, 10 },
         group("VGrid with Fixed-Sized, Aligned Elements", make_vgrid(), 0.9, false)
      ),
      margin({ 10, 10, 10, 10 },
         group("HGrid with Fixed-Sized, Aligned Elements", make_hgrid(), 0.9, false)
      )
   );
}

template <typename MenuItem>
auto make_popup_menu(
   MenuItem& item1,
   MenuItem& item2,
   MenuItem& item3,
   MenuItem& item4,
   MenuItem& item5
)
{
   auto popup  = button_menu("Layout", menu_position::bottom_left);

   auto menu =
      layer(
         vtile(
            link(item1), link(item2),
            link(item3), link(item4), link(item5)
         ),
         panel{}
      );

   popup.menu(std::move(menu));
   return popup;
}

int main(int argc, char* argv[])
{
   app _app(argc, argv);
   window _win(_app.name(), window::standard, { 50, 50, 1024, 768 });

   _win.on_close = [&_app]() { _app.stop(); };

   auto align_menu_item = menu_item("Fixed-Sized, Aligned Elements");
   auto percentages_menu_item = menu_item("Stretchable Elements");
   auto mixed_menu_item = menu_item("Fixed-Sized and Stretchable Elements");
   auto flow_menu_item = menu_item("Flow Elements");
   auto grid_menu_item = menu_item("Grid Elements");

   auto aligns = share(make_aligns());
   auto percentages = share(make_percentages());
   auto mixed = share(make_mixed());
   auto flow = share(make_flow());
   auto grids = share(make_grids());
   auto content = hold_any(aligns);

   view view_(_win);

   align_menu_item.on_click = [&]()
   {
      content = aligns;
      view_.layout(content);
   };

   percentages_menu_item.on_click = [&]()
   {
      content = percentages;
      view_.layout(content);
   };

   mixed_menu_item.on_click = [&]()
   {
      content = mixed;
      view_.layout(content);
   };

   flow_menu_item.on_click = [&]()
   {
      content = flow;
      view_.layout(content);
   };

   grid_menu_item.on_click = [&]()
   {
      content = grids;
      view_.layout(content);
   };

   auto menu = make_popup_menu(
      align_menu_item,
      percentages_menu_item,
      mixed_menu_item,
      flow_menu_item,
      grid_menu_item
   );

   auto top = align_right(hsize(120, menu));
   auto main_pane = pane(top, link(content), false);
   auto main_element = margin({ 10, 10, 10, 10 }, main_pane);

   view_.content(
      main_element,
      background
   );

   _app.run();
   return 0;
}
