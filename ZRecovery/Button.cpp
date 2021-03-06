#include "stdafx.h"
#include "Button.h"

void Button::bind_event_handler(std::string event_name, IUIElement::EventHandler handler)
{
	if (case_insensitive_compare(event_name, "onClick")) {
		onClick = handler;
	}
}

HTMLUI_TypeInfo::UIConstructor Button::create_from_html = [](HTMLUI_UIDescriptor& des) -> std::shared_ptr<UIBase> {
	auto ret = std::shared_ptr<UIBase>(new Button(des.parent, des.nameW(), des.position()), [](auto& p) {delete (Button*)p; });
	ret->create();
	return ret;
};

HTMLUI_TypeInfo::UIMatchAttrMap Button::match_attributes {
	{"class", "button"},
	{"tag", "button"}
};

HTMLUI_TypeInfo::UISupportedEventsSet Button::supported_events{
	"onClick"
};