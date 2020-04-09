/*
Copyright IBM Corp. 2016 All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
// #cgo LDFLAGS: ${SRCDIR}/libapp.a ${SRCDIR}/interface/libenclave_stub_u.a /opt/intel/sgxsdk/lib64/libsgx_urts.so /opt/openssl-1.1.1f/lib/libcrypto.so 
limitations under the License.
*/

package main

// #cgo CFLAGS: -I${SRCDIR}/ -I/opt/intel/sgxsdk/include/
// #cgo LDFLAGS: ${SRCDIR}/libapp.a /opt/intel/sgxsdk/lib64/libsgx_urts.so /opt/openssl-1.1.1f/lib/libcrypto.so
// #include<./app/app.h>
import "C"

func main() {
  //1: keygen
  //2: sign
  C.ff(1)
  C.ff(2)
}
