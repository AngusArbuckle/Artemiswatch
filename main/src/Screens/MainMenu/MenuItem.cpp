#include "MenuItem.h"

MenuItem::MenuItem(lv_obj_t* parent, const char* imagePath, const char* labelText) : LVObject(parent){
	lv_obj_set_flex_flow(*this, LV_FLEX_FLOW_COLUMN);
	lv_obj_set_flex_align(*this, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

	lv_obj_set_size(*this, lv_pct(100), 128);
	lv_obj_set_style_pad_top(*this, 12, 0);

	imageContainer = lv_obj_create(*this);
	lv_obj_set_size(imageContainer, lv_pct(100), LV_SIZE_CONTENT);
	lv_obj_set_style_pad_ver(imageContainer, 6, 0);
	lv_obj_set_style_border_opa(imageContainer, LV_OPA_COVER, 0);
	lv_obj_set_style_border_color(imageContainer, lv_color_make(255, 101, 0), 0);
	lv_obj_set_style_border_width(imageContainer, 1, 0);
	lv_obj_set_style_border_side(imageContainer, LV_BORDER_SIDE_TOP, 0);

	image = lv_img_create(imageContainer);
	lv_obj_center(image);
	lv_img_set_src(image, imagePath);


	label = lv_label_create(*this);
	lv_label_set_text(label, labelText);
	lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_set_width(label, lv_pct(100));
	lv_obj_set_style_pad_ver(label, 3, 0);
	lv_obj_set_style_bg_opa(label, LV_OPA_COVER, 0);
	lv_obj_set_style_bg_color(label, lv_color_make(255, 101, 0), 0);
	lv_obj_set_style_text_color(label, lv_color_black(), 0);


	lv_obj_add_event_cb(*this, [](lv_event_t* e){
		auto item = static_cast<MenuItem*>(e->user_data);
		item->onFocus();
	}, LV_EVENT_FOCUSED, this);

	lv_obj_add_event_cb(*this, [](lv_event_t* e){
		auto item = static_cast<MenuItem*>(e->user_data);
		item->onDefocus();
	}, LV_EVENT_DEFOCUSED, this);
}

void MenuItem::constructVis(const char* imagePath, const char* labelText){
	lv_img_set_src(image, imagePath);
	lv_label_set_text(label, labelText);

}
