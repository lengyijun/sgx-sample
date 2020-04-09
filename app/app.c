/*
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <getopt.h>

#include <openssl/evp.h>

#include "app.h"


static struct option long_options[] = {
    {"keygen", no_argument, 0, 0},
    {"sign", no_argument, 0, 0},
    {"enclave-path", required_argument, 0, 0},
    {"statefile", required_argument, 0, 0},
    {"signature", required_argument, 0, 0},
    {"public-key", required_argument, 0, 0},
    {0, 0, 0, 0}};


/**
../app/app --sign --enclave-path `pwd`/../enclave/enclave.signed.so --statefile sealeddata.bin --signature Sensor_Data.signature ../Sensor_Data
../app/app --keygen --enclave-path `pwd`/../enclave/enclave.signed.so --statefile sealeddata.bin --public-key secp256r1.pem
 * main()
 */
int ff(int op)
{
    bool opt_keygen = false;
    bool opt_sign = false;
    const char *opt_enclave_path = "/home/sgx/sgx-sample/enclave.signed.so";
    const char *opt_statefile = "sealeddata.bin" ;
    const char *opt_signature_file = "Sensor_Data.signature";
    const char *opt_input_file =  "../Sensor_Data";
    const char *opt_public_key_file = "secp256r1.pem";

    if(op==1){
      opt_keygen=true;
    }
    if(op==2){
      opt_sign=true;
    }
    if(!opt_sign && !opt_keygen){
      return -1;
    }

    OpenSSL_add_all_algorithms(); /* Init OpenSSL lib */

    bool success_status = create_enclave(opt_enclave_path) &&
                          enclave_get_buffer_sizes() &&
                          allocate_buffers() &&
                          (opt_sign ? load_enclave_state(opt_statefile) : true) &&
                          (opt_keygen ? enclave_generate_key() : true) &&
                          (opt_sign ? load_input_file(opt_input_file) : true) &&
                          (opt_sign ? enclave_sign_data() : true) &&
                          save_enclave_state(opt_statefile) &&
                          (opt_sign ? save_signature(opt_signature_file) : true) &&
                          (opt_keygen ? save_public_key(opt_public_key_file) : true);

    if (sgx_lasterr != SGX_SUCCESS)
    {
        fprintf(stderr, "[GatewayApp]: ERROR: %s\n", decode_sgx_status(sgx_lasterr));
    }

    destroy_enclave();
    cleanup_buffers();

    return success_status ? EXIT_SUCCESS : EXIT_FAILURE;
}
