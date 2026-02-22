#ifndef _FOCALTECH_TOUCH_F9S_NAMESPACE_H_
#define _FOCALTECH_TOUCH_F9S_NAMESPACE_H_

/*
 * Namespace F9S FocalTech touchscreen driver symbols so it can be linked
 * built-in alongside other FocalTech driver trees under LTO.
 */

/* global data */
#define fts_data                        f9s_fts_data

/* firmware blobs / upgrade tables */
#define fw_file                         f9s_fw_file
#define fw_file2                        f9s_fw_file2
#define fw_file3                        f9s_fw_file3
#define module_list                     f9s_module_list
#define upgrade_func_list               f9s_upgrade_func_list
#define fwupgrade                       f9s_fwupgrade

/* ini/test globals */
#define ic_types                        f9s_ic_types

/* bus / reg access */
#define fts_read                        f9s_fts_read
#define fts_write                       f9s_fts_write
#define fts_read_reg                    f9s_fts_read_reg
#define fts_write_reg                   f9s_fts_write_reg
#define fts_bus_init                    f9s_fts_bus_init
#define fts_bus_exit                    f9s_fts_bus_exit

/* core helpers */
#define fts_wait_tp_to_valid            f9s_fts_wait_tp_to_valid
#define fts_tp_state_recovery           f9s_fts_tp_state_recovery
#define fts_reset_proc                  f9s_fts_reset_proc
#define fts_irq_disable                 f9s_fts_irq_disable
#define fts_irq_enable                  f9s_fts_irq_enable
#define fts_hid2std                     f9s_fts_hid2std
#define fts_release_all_finger          f9s_fts_release_all_finger
#define fts_input_event                 f9s_fts_input_event

/* ex_fun/sysfs */
#define fts_create_apk_debug_channel    f9s_fts_create_apk_debug_channel
#define fts_release_apk_debug_channel   f9s_fts_release_apk_debug_channel
#define fts_create_sysfs                f9s_fts_create_sysfs
#define fts_remove_sysfs                f9s_fts_remove_sysfs

/* ex_mode */
#define fts_ex_mode_recovery            f9s_fts_ex_mode_recovery
#define fts_ex_mode_init                f9s_fts_ex_mode_init
#define fts_ex_mode_exit                f9s_fts_ex_mode_exit

/* gesture/fod */
#define fts_gesture_enable              f9s_fts_gesture_enable
#define fts_create_gesture_sysfs        f9s_fts_create_gesture_sysfs
#define fts_gesture_readdata            f9s_fts_gesture_readdata
#define fts_gesture_recovery            f9s_fts_gesture_recovery
#define fts_gesture_suspend             f9s_fts_gesture_suspend
#define fts_gesture_resume              f9s_fts_gesture_resume
#define fts_gesture_init                f9s_fts_gesture_init
#define fts_gesture_exit                f9s_fts_gesture_exit
#define fts_fod_readdata                f9s_fts_fod_readdata
#define fts_fod_recovery                f9s_fts_fod_recovery
#define fts_fod_suspend                 f9s_fts_fod_suspend
#define fts_fod_resume                  f9s_fts_fod_resume
#define fts_fod_pay                     f9s_fts_fod_pay

/* esdcheck */
#define fts_esdcheck_set_intr           f9s_fts_esdcheck_set_intr
#define fts_esdcheck_get_status         f9s_fts_esdcheck_get_status
#define fts_esdcheck_proc_busy          f9s_fts_esdcheck_proc_busy
#define fts_esdcheck_switch             f9s_fts_esdcheck_switch
#define fts_esdcheck_suspend            f9s_fts_esdcheck_suspend
#define fts_esdcheck_resume             f9s_fts_esdcheck_resume
#define fts_create_esd_sysfs            f9s_fts_create_esd_sysfs
#define fts_esdcheck_init               f9s_fts_esdcheck_init
#define fts_esdcheck_exit               f9s_fts_esdcheck_exit

/* point report check */
#define fts_prc_queue_work              f9s_fts_prc_queue_work
#define fts_point_report_check_init     f9s_fts_point_report_check_init
#define fts_point_report_check_exit     f9s_fts_point_report_check_exit

/* fw upgrade */
#define fts_fwupg_reset_in_boot         f9s_fts_fwupg_reset_in_boot
#define fts_fwupg_enter_into_boot       f9s_fts_fwupg_enter_into_boot
#define fts_fwupg_erase                 f9s_fts_fwupg_erase
#define fts_fwupg_ecc_cal               f9s_fts_fwupg_ecc_cal
#define fts_fwupg_upgrade               f9s_fts_fwupg_upgrade
#define fts_fwupg_init                  f9s_fts_fwupg_init
#define fts_fwupg_exit                  f9s_fts_fwupg_exit
#define fts_read_file                   f9s_fts_read_file
#define fts_upgrade_bin                 f9s_fts_upgrade_bin
#define fts_enter_test_environment      f9s_fts_enter_test_environment

/* ini/test exported helpers */
#define get_keyword_value               f9s_get_keyword_value
#define fts_test_get_testparam_from_ini f9s_fts_test_get_testparam_from_ini

/* focaltech_test core globals/helpers */
#define fts_ftest                       f9s_fts_ftest
#define test_func_list                  f9s_test_func_list
#define sys_delay                       f9s_sys_delay
#define focal_abs                       f9s_focal_abs
#define fts_malloc                      f9s_fts_malloc
#define fts_free_proc                   f9s_fts_free_proc
#define print_buffer                    f9s_print_buffer
#define fts_test_read_reg               f9s_fts_test_read_reg
#define fts_test_write_reg              f9s_fts_test_write_reg
#define fts_test_read                   f9s_fts_test_read
#define fts_test_write                  f9s_fts_test_write
#define enter_work_mode                 f9s_enter_work_mode
#define enter_factory_mode              f9s_enter_factory_mode
#define read_mass_data                  f9s_read_mass_data
#define short_get_adcdata_incell        f9s_short_get_adcdata_incell
#define wait_state_update               f9s_wait_state_update
#define start_scan                      f9s_start_scan
#define get_rawdata                     f9s_get_rawdata
#define chip_clb                        f9s_chip_clb
#define get_cb_incell                   f9s_get_cb_incell
#define get_cb_sc                       f9s_get_cb_sc
#define compare_data                    f9s_compare_data
#define compare_array                   f9s_compare_array
#define show_data                       f9s_show_data
#define mapping_switch                  f9s_mapping_switch
#define get_fw_wp                       f9s_get_fw_wp
#define get_cb_mc_sc                    f9s_get_cb_mc_sc
#define get_rawdata_mc_sc               f9s_get_rawdata_mc_sc
#define get_rawdata_mc                  f9s_get_rawdata_mc
#define short_get_adc_data_mc           f9s_short_get_adc_data_mc
#define compare_mc_sc                   f9s_compare_mc_sc
#define show_data_mc_sc                 f9s_show_data_mc_sc
#define fts_test_entry                  f9s_fts_test_entry
#define fts_test_save_data              f9s_fts_test_save_data
#define fts_test_init                   f9s_fts_test_init
#define fts_test_exit                   f9s_fts_test_exit

#endif /* _FOCALTECH_TOUCH_F9S_NAMESPACE_H_ */
