/*
 * zkey - Generate, re-encipher, and validate secure keys
 *
 * This header file defines functions for Key Management System (KMS) plugin
 * handling
 *
 * Copyright IBM Corp. 2020
 *
 * s390-tools is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef KMS_H
#define KMS_H

#include "kms-plugin.h"
#include "properties.h"
#include "keystore.h"

struct kms_info {
	void *plugin_lib;
	const struct kms_functions *funcs;
	char *plugin_name;
	struct properties *props;
	struct kms_apqn *apqns;
	size_t num_apqns;
	kms_handle_t handle;
};

struct keystore;

int list_kms_plugins(bool verbose);

int check_for_kms_plugin(struct kms_info *kms_info, bool verbose);

int init_kms_plugin(struct kms_info *kms_info, bool verbose);

void free_kms_plugin(struct kms_info *kms_info);

void print_last_kms_error(const struct kms_info *kms_info);

int bind_kms_plugin(struct keystore *keystore, const char *plugin,
		    bool verbose);

int unbind_kms_plugin(struct kms_info *kms_info, struct keystore *keystore,
		      bool verbose);

int print_kms_info(struct kms_info *kms_info);

int get_kms_options(struct kms_info *kms_info, struct util_opt *opt_vec,
		    const char *placeholder_cmd, const char *plugin_command,
		    const char *opt_vec_command, int *first_plugin_opt,
		    bool verbose);

int handle_kms_option(struct kms_info *kms_info, struct util_opt *opt_vec,
		      int first_kms_option, const char *command, int option,
		      const char *optarg, struct kms_option **kms_options,
		      size_t *num_kms_options, bool verbose);

#endif