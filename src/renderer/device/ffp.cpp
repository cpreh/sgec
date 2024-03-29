#include <sgec/result.h>
#include <sgec/impl/renderer/device/ffp.hpp>
#include <sgec/renderer/context/ffp_fwd.h>
#include <sgec/renderer/device/ffp.h>
#include <sgec/renderer/target/onscreen_fwd.h>

extern "C" struct sgec_renderer_context_ffp *
sgec_renderer_device_ffp_begin_rendering(struct sgec_renderer_device_ffp *const _device)
try
{
  return _device->begin_rendering();
}
catch (...)
{
  return nullptr;
}

extern "C" sgec_result sgec_renderer_device_ffp_end_rendering(
    struct sgec_renderer_device_ffp *const _device,
    struct sgec_renderer_context_ffp *const _context)
try
{
  _device->end_rendering(_context);

  return sgec_result_ok;
}
catch (...)
{
  return sgec_result_error;
}

extern "C" struct sgec_renderer_target_onscreen *
sgec_renderer_device_ffp_onscreen_target(struct sgec_renderer_device_ffp *const _device)
{
  return &_device->onscreen_target();
}
