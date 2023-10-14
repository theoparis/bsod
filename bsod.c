#include <drm/drm_client.h>
#include <drm/drm_crtc.h>
#include <drm/drm_device.h>
#include <linux/fb.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/panic_notifier.h>

static int bsod_panic_handler(struct notifier_block *nb, unsigned long val,
							  void *data) {
	
	// TODO: figure out how to write to a drm device or framebuffer

	return NOTIFY_OK;
}

static struct notifier_block bsod_panic_notifier_block = {
	.notifier_call = bsod_panic_handler,
};

static int __init bsod_init(void) {
	atomic_notifier_chain_register(&panic_notifier_list,
								   &bsod_panic_notifier_block);
	return 0;
}

static void __exit bsod_exit(void) {
	atomic_notifier_chain_unregister(&panic_notifier_list,
									 &bsod_panic_notifier_block);
}

MODULE_LICENSE("Dual MIT/GPL");
module_init(bsod_init);
module_exit(bsod_exit);
MODULE_AUTHOR("Theo Paris");
MODULE_DESCRIPTION("Windows moment");
