#include <sgec/impl/window/system.hpp>
#include <sgec/impl/window/translate_event.hpp>
#include <sgec/window/event.h>
#include <sge/window/system.hpp>
#include <awl/event/base.hpp>
#include <awl/event/container.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <fcppt/const.hpp>
#include <fcppt/algorithm/append.hpp>
#include <fcppt/container/pop_front.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


sgec_window_system::sgec_window_system(
	sge::window::system &_system
)
:
	system_{
		_system
	},
	event_queue_{},
	exit_code_{}
{
}

sgec_window_system::~sgec_window_system()
{
}

bool
sgec_window_system::next_event(
	sgec_window_event &_result
)
{
	for(
		;;
	)
	{
		if(
			fcppt::optional::maybe(
				fcppt::container::pop_front(
					event_queue_
				),
				fcppt::const_(
					false
				),
				[
					&_result
				](
					awl::event::base_unique_ptr &&_event
				)
				{
					return
						fcppt::optional::maybe(
							sgec::impl::window::translate_event(
								*_event
							),
							fcppt::const_(
								false
							),
							[
								&_result
							](
								sgec_window_event const &_window_event
							)
							{
								_result =
									_window_event;

								return
									true;
							}
						);
				}
			)
		)
			break;

		if(
			fcppt::either::match(
				system_.next(),
				[
					this
				](
					awl::main::exit_code const _exit_code
				)
				{
					this->exit_code_ =
						awl::main::optional_exit_code{
							_exit_code
						};

					return
						true;
				},
				[
					this
				](
					awl::event::container &&_events
				)
				{
					fcppt::algorithm::append(
						this->event_queue_,
						std::move(
							_events
						)
					);

					return
						false;
				}
			)
		)
			return
				false;
	}

	return
		true;
}

void
sgec_window_system::quit(
	int const _exit_code
)
{
	system_.quit(
		awl::main::exit_code(
			_exit_code
		)
	);
}

int
sgec_window_system::exit_code() const
{
	return
		fcppt::optional::from(
			exit_code_,
			fcppt::const_(
				awl::main::exit_code{
					0
				}
			)
		).get();
}
