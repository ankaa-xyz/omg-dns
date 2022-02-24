//
//  omg_dns_extension.h
//  tun2socks
//
//  Created by wufan on 2017/4/19.
//  Copyright © 2017年 atoi. All rights reserved.
//

#ifndef omg_dns_extension_h
#define omg_dns_extension_h

#include "omg_dns.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
 
void omg_dns_set_id(omg_dns_t* dns, uint16_t id);
void omg_dns_set_qr(omg_dns_t* dns, int qr);
void omg_dns_set_opcode(omg_dns_t* dns, int opcode);
void omg_dns_set_aa(omg_dns_t* dns, int aa);
void omg_dns_set_tc(omg_dns_t* dns, int tc);
void omg_dns_set_rd(omg_dns_t* dns, int rd);
void omg_dns_set_ra(omg_dns_t* dns, int ra);
void omg_dns_set_z(omg_dns_t* dns, int z);
void omg_dns_set_ad(omg_dns_t* dns, int ad);
void omg_dns_set_cd(omg_dns_t* dns, int cd);
void omg_dns_set_rcode(omg_dns_t* dns, int code);
void omg_dns_set_qdcount(omg_dns_t* dns, uint16_t count);
void omg_dns_set_ancount(omg_dns_t* dns, uint16_t count);
void omg_dns_set_nscount(omg_dns_t* dns, uint16_t count);
void omg_dns_set_arcount(omg_dns_t* dns, uint16_t count);
    
int omg_dns_build_header(omg_dns_t* dns, uint8_t* buffer, size_t length);
int omg_dns_build_rr(omg_dns_rr_t* rr, const uint8_t* buffer, size_t length);
//int omg_dns_build(omg_dns_t* dns, const uint8_t* buffer, size_t length);
    
#ifdef __cplusplus
}
#endif

#endif /* omg_dns_extension_h */
