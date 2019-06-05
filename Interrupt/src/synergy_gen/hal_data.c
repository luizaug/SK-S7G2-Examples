/* generated HAL source file - do not edit */
#include "hal_data.h"
#if (13) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_external_irq11) && !defined(SSP_SUPPRESS_ISR_ICU11)
SSP_VECTOR_DEFINE( icu_irq_isr, ICU, IRQ11);
#endif
#endif
static icu_instance_ctrl_t g_external_irq11_ctrl;
static const external_irq_cfg_t g_external_irq11_cfg =
{ .channel = 11,
  .trigger = EXTERNAL_IRQ_TRIG_BOTH_EDGE,
  .filter_enable = false,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .autostart = true,
  .p_callback = g_external_irq11_callback,
  .p_context = &g_external_irq11,
  .p_extend = NULL,
  .irq_ipl = (13), };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq11 =
{ .p_ctrl = &g_external_irq11_ctrl, .p_cfg = &g_external_irq11_cfg, .p_api = &g_external_irq_on_icu };
void g_hal_init(void)
{
    g_common_init ();
}
