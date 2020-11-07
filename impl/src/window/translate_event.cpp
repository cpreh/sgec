#include <sgec/impl/input/cursor/translate_button_event.hpp>
#include <sgec/impl/input/cursor/translate_move_event.hpp>
#include <sgec/impl/input/cursor/translate_scroll_event.hpp>
#include <sgec/impl/input/focus/translate_key_event.hpp>
#include <sgec/impl/input/focus/translate_key_repeat_event.hpp>
#include <sgec/impl/input/focus/translate_text_event.hpp>
#include <sgec/impl/input/keyboard/translate_key_event.hpp>
#include <sgec/impl/input/mouse/translate_axis_event.hpp>
#include <sgec/impl/input/mouse/translate_button_event.hpp>
#include <sgec/impl/renderer/translate_render_event.hpp>
#include <sgec/impl/window/translate_event.hpp>
#include <sgec/window/event.h>
#include <sgec/window/event_type.h>
#include <sge/input/cursor/event/button.hpp>
#include <sge/input/cursor/event/move.hpp>
#include <sge/input/cursor/event/scroll.hpp>
#include <sge/input/focus/event/key.hpp>
#include <sge/input/focus/event/key_repeat.hpp>
#include <sge/input/focus/event/text.hpp>
#include <sge/input/keyboard/event/key.hpp>
#include <sge/input/mouse/event/axis.hpp>
#include <sge/input/mouse/event/button.hpp>
#include <sge/renderer/event/render.hpp>
#include <awl/event/base.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/cast/dynamic_fun.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/variant/dynamic_cast.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


fcppt::optional::object<
	sgec_window_event
>
sgec::impl::window::translate_event(
	awl::event::base const &_event
)
{
	return
		fcppt::optional::map(
			fcppt::variant::dynamic_cast_<
				metal::list<
					sge::input::cursor::event::button const,
					sge::input::cursor::event::move const,
					sge::input::cursor::event::scroll const,
					sge::input::focus::event::text const,
					sge::input::focus::event::key const,
					sge::input::focus::event::key_repeat const,
					sge::input::keyboard::event::key const,
					sge::input::mouse::event::axis const,
					sge::input::mouse::event::button const,
					sge::renderer::event::render const
				>,
				fcppt::cast::dynamic_fun
			>(
				_event
			),
			[](
				auto const &_variant
			)
			{
				return
					fcppt::variant::match(
						_variant,
						[](
							fcppt::reference<
								sge::input::cursor::event::button const
							> const _button_event
						)
						{
							sgec_window_event result{};

							result.type =
								sgec_window_event_type_cursor_button;

							result.cursor_button = // NOLINT(cppcoreguidelines-pro-type-union-access)
								sgec::impl::input::cursor::translate_button_event(
									_button_event.get()
								);

							return
								result;
						},
						[](
							fcppt::reference<
								sge::input::cursor::event::move const
							> const _move_event
						)
						{
							sgec_window_event result{};

							result.type =
								sgec_window_event_type_cursor_move;

							result.cursor_move = // NOLINT(cppcoreguidelines-pro-type-union-access)
								sgec::impl::input::cursor::translate_move_event(
									_move_event.get()
								);

							return
								result;
						},
						[](
							fcppt::reference<
								sge::input::cursor::event::scroll const
							> const _scroll_event
						)
						{
							sgec_window_event result{};

							result.type =
								sgec_window_event_type_cursor_scroll;

							result.cursor_scroll = // NOLINT(cppcoreguidelines-pro-type-union-access)
								sgec::impl::input::cursor::translate_scroll_event(
									_scroll_event.get()
								);

							return
								result;
						},
						[](
							fcppt::reference<
								sge::input::focus::event::text const
							> const _text_event
						)
						{
							sgec_window_event result{};

							result.type =
								sgec_window_event_type_focus_text;

							result.focus_text = // NOLINT(cppcoreguidelines-pro-type-union-access)
								sgec::impl::input::focus::translate_text_event(
									_text_event.get()
								);

							return
								result;
						},
						[](
							fcppt::reference<
								sge::input::focus::event::key const
							> const _key_event
						)
						{
							sgec_window_event result{};

							result.type =
								sgec_window_event_type_focus_key;

							result.focus_key = // NOLINT(cppcoreguidelines-pro-type-union-access)
								sgec::impl::input::focus::translate_key_event(
									_key_event.get()
								);

							return
								result;
						},
						[](
							fcppt::reference<
								sge::input::focus::event::key_repeat const
							> const _key_repeat_event
						)
						{
							sgec_window_event result{};

							result.type =
								sgec_window_event_type_focus_key_repeat;

							result.focus_key_repeat = // NOLINT(cppcoreguidelines-pro-type-union-access)
								sgec::impl::input::focus::translate_key_repeat_event(
									_key_repeat_event.get()
								);

							return
								result;
						},
						[](
							fcppt::reference<
								sge::input::keyboard::event::key const
							> const _key_event
						)
						{
							sgec_window_event result{};

							result.type =
								sgec_window_event_type_keyboard_key;

							result.keyboard_key = // NOLINT(cppcoreguidelines-pro-type-union-access)
								sgec::impl::input::keyboard::translate_key_event(
									_key_event.get()
								);

							return
								result;
						},
						[](
							fcppt::reference<
								sge::input::mouse::event::axis const
							> const _axis_event
						)
						{
							sgec_window_event result{};

							result.type =
								sgec_window_event_type_mouse_axis;

							result.mouse_axis = // NOLINT(cppcoreguidelines-pro-type-union-access)
								sgec::impl::input::mouse::translate_axis_event(
									_axis_event.get()
								);

							return
								result;
						},
						[](
							fcppt::reference<
								sge::input::mouse::event::button const
							> const _button_event
						)
						{
							sgec_window_event result{};

							result.type =
								sgec_window_event_type_mouse_button;

							result.mouse_button = // NOLINT(cppcoreguidelines-pro-type-union-access)
								sgec::impl::input::mouse::translate_button_event(
									_button_event.get()
								);

							return
								result;
						},
						[](
							fcppt::reference<
								sge::renderer::event::render const
							> const _render_event
						)
						{
							sgec_window_event result{};

							result.type =
								sgec_window_event_type_render;

							result.render = // NOLINT(cppcoreguidelines-pro-type-union-access)
								sgec::impl::renderer::translate_render_event(
									_render_event.get()
								);

							return
								result;
						}
					);
			}
		);
}
