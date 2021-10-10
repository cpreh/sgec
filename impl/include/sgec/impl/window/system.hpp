#ifndef SGEC_IMPL_WINDOW_SYSTEM_HPP_INCLUDED
#define SGEC_IMPL_WINDOW_SYSTEM_HPP_INCLUDED

#include <sgec/window/event_fwd.h>
#include <sgec/window/system_fwd.h>
#include <sge/window/system_ref.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <deque>
#include <fcppt/config/external_end.hpp>

struct sgec_window_system
{
  FCPPT_NONMOVABLE(sgec_window_system);

public:
  explicit sgec_window_system(sge::window::system_ref);

  ~sgec_window_system();

  [[nodiscard]] bool next_event(fcppt::reference<sgec_window_event>);

  void quit(int exit_code);

  [[nodiscard]] int exit_code() const;

private:
  sge::window::system_ref const system_;

  using event_queue = std::deque<awl::event::base_unique_ptr>;

  event_queue event_queue_;

  awl::main::optional_exit_code exit_code_;
};

#endif
