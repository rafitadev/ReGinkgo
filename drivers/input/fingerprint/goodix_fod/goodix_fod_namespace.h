#ifndef _GOODIX_FOD_NAMESPACE_H_
#define _GOODIX_FOD_NAMESPACE_H_

/*
 * Namespace Goodix FOD fingerprint driver symbols so it can be linked
 * built-in alongside other Goodix/GF driver trees under LTO.
 */

/* gf_spi.c globals */
#define maps            goodix_fod_maps

/* platform.c */
#define gf_parse_dts    goodix_fod_gf_parse_dts
#define gf_cleanup      goodix_fod_gf_cleanup
#define gf_power_on     goodix_fod_gf_power_on
#define gf_power_off    goodix_fod_gf_power_off
#define gf_hw_reset     goodix_fod_gf_hw_reset
#define gf_irq_num      goodix_fod_gf_irq_num

/* netlink.c */
#define sendnlmsg       goodix_fod_sendnlmsg
#define nl_data_ready   goodix_fod_nl_data_ready
#define netlink_init    goodix_fod_netlink_init
#define netlink_exit    goodix_fod_netlink_exit
#define nl_sk           goodix_fod_nl_sk

#endif /* _GOODIX_FOD_NAMESPACE_H_ */
