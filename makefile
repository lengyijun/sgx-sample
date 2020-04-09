#
# Copyright (C) 2011-2019 Intel Corporation
#
# SPDX-License-Identifier: BSD-3-Clause
#

include common/common.mk

.PHONY: all clean

all:
	$(MAKE) $(MFLAGS) -C enclave SGX_MODE=$(SGX_MODE) $(MAKECMDGOALS)
	$(MAKE) $(MFLAGS) -C app SGX_MODE=$(SGX_MODE) $(MAKECMDGOALS)
	cp enclave/enclave.signed.so .
	go build

clean:
	$(MAKE) $(MFLAGS) -C enclave SGX_MODE=$(SGX_MODE) $(MAKECMDGOALS)
	$(MAKE) $(MFLAGS) -C app SGX_MODE=$(SGX_MODE) $(MAKECMDGOALS)
	rm -fr demo_openssl demo_sgx
	rm -rf sgx-sample *.so
