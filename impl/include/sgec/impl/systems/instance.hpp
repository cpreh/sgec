#ifndef SGEC_IMPL_SYSTEMS_INSTANCE_HPP_INCLUDED
#define SGEC_IMPL_SYSTEMS_INSTANCE_HPP_INCLUDED

#include <sgec/audio/loader_fwd.h>
#include <sgec/audio/player_fwd.h>
#include <sgec/font/system_fwd.h>
#include <sgec/image2d/system_fwd.h>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/systems/cursor_option.h>
#include <sgec/systems/instance_fwd.h>
#include <sgec/window/system_fwd.h>
#include <sgec/window/unit.h>
#include <sge/systems/instance_decl.hpp>
#include <sge/systems/renderer_caps.hpp>
#include <sge/systems/with_audio_loader.hpp>
#include <sge/systems/with_audio_player.hpp>
#include <sge/systems/with_font.hpp>
#include <sge/systems/with_image2d.hpp>
#include <sge/systems/with_input.hpp>
#include <sge/systems/with_renderer.hpp>
#include <sge/systems/with_window.hpp>
#include <sge/window/dim_fwd.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/unique_ptr_decl.hpp>

struct sgec_systems_instance
{
  FCPPT_NONMOVABLE(sgec_systems_instance);

public:
  sgec_systems_instance(
      char const *, sgec_window_unit, sgec_window_unit, sgec_systems_cursor_option);

  sgec_systems_instance(char const *, sge::window::dim const &, sgec_systems_cursor_option);

  ~sgec_systems_instance();

  [[nodiscard]] sgec_renderer_device_ffp *renderer();

  [[nodiscard]] sgec_window_system *window_system();

  [[nodiscard]] sgec_image2d_system *image2d_system();

  [[nodiscard]] sgec_font_system *font_system();

  [[nodiscard]] sgec_audio_loader *audio_loader();

  [[nodiscard]] sgec_audio_player *audio_player();

private:
  using instance = sge::systems::instance<
      sge::systems::with_renderer<sge::systems::renderer_caps::ffp>,
      sge::systems::with_window,
      sge::systems::with_input,
      sge::systems::with_image2d,
      sge::systems::with_font,
      sge::systems::with_audio_loader,
      sge::systems::with_audio_player>;

  instance impl_;

  using scoped_renderer_ptr = fcppt::unique_ptr<sgec_renderer_device_ffp>;

  scoped_renderer_ptr const renderer_;

  using scoped_window_system_ptr = fcppt::unique_ptr<sgec_window_system>;

  scoped_window_system_ptr const window_system_;

  using scoped_image2d_system_ptr = fcppt::unique_ptr<sgec_image2d_system>;

  scoped_image2d_system_ptr const image2d_system_;

  using scoped_font_system_ptr = fcppt::unique_ptr<sgec_font_system>;

  scoped_font_system_ptr const font_system_;

  using scoped_audio_loader_ptr = fcppt::unique_ptr<sgec_audio_loader>;

  scoped_audio_loader_ptr const audio_loader_;

  using scoped_audio_player_ptr = fcppt::unique_ptr<sgec_audio_player>;

  scoped_audio_player_ptr const audio_player_;
};

#endif
