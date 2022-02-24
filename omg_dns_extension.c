//
//  omg_dns_extension.c
//  tun2socks
//
//  Created by wufan on 2017/4/19.
//  Copyright © 2017年 atoi. All rights reserved.
//

#include "omg_dns_extension.h"

void omg_dns_set_id(omg_dns_t* dns, uint16_t id) {
    dns->id = id;
}
void omg_dns_set_qr(omg_dns_t* dns, int qr) {
    dns->qr = qr;
}
void omg_dns_set_opcode(omg_dns_t* dns, int opcode) {
    dns->opcode = opcode;
}
void omg_dns_set_aa(omg_dns_t* dns, int aa) {
    dns->aa = aa;
}
void omg_dns_set_tc(omg_dns_t* dns, int tc) {
    dns->tc = tc;
}
void omg_dns_set_rd(omg_dns_t* dns, int rd) {
    dns->rd = rd;
}
void omg_dns_set_ra(omg_dns_t* dns, int ra) {
    dns->ra = ra;
}
void omg_dns_set_z(omg_dns_t* dns, int z) {
    dns->z = z;
}
void omg_dns_set_ad(omg_dns_t* dns, int ad) {
    dns->ad = ad;
}
void omg_dns_set_cd(omg_dns_t* dns, int cd) {
    dns->cd = cd;
}
void omg_dns_set_rcode(omg_dns_t* dns, int code) {
    dns->rcode = code;
}
void omg_dns_set_qdcount(omg_dns_t* dns, uint16_t count) {
    dns->qdcount = count;
}
void omg_dns_set_ancount(omg_dns_t* dns, uint16_t count) {
    dns->ancount = count;
}
void omg_dns_set_nscount(omg_dns_t* dns, uint16_t count) {
    dns->nscount = count;
}
void omg_dns_set_arcount(omg_dns_t* dns, uint16_t count) {
    dns->arcount = count;
}

int omg_dns_build_header(omg_dns_t* dns, uint8_t* buffer, size_t length) {
    uint8_t byte;

    if (!dns) {
        return OMG_DNS_EINVAL;
    }

#define set8(v, p, l) \
    if (l < 1) { \
        return OMG_DNS_EINCOMP; \
    } \
    *(uint8_t *)(p) = (v); \
    p += 1; l-= 1
        
#define set16(v, p, l) \
    if (l < 2) { \
        return OMG_DNS_EINCOMP; \
    } \
    *(uint16_t *)(p) = htons(v); \
    p += 2; l-= 2
    
    
    set16(dns->id, buffer, length);
    dns->bytes_parsed += 2;

    byte = ((dns->qr ? 1 : 0) << 7) |
           ((dns->opcode) << 3) |
           ((dns->aa ? 1 : 0) << 2) |
           ((dns->tc ? 1 : 0) << 1) |
           ((dns->rd ? 1 : 0) << 0);
    set8(byte, buffer, length);
    dns->bytes_parsed += 1;

    byte = ((dns->ra ? 1 : 0) << 7) |
           ((dns->z  ? 1 : 0) << 6) |
           ((dns->ad ? 1 : 0) << 5) |
           ((dns->cd ? 1 : 0) << 4) |
           ((dns->rcode) << 0);
    set8(byte, buffer, length);
    dns->bytes_parsed += 1;

    set16(dns->qdcount, buffer, length);
    dns->bytes_parsed += 2;

    set16(dns->ancount, buffer, length);
    dns->bytes_parsed += 2;

    set16(dns->nscount, buffer, length);
    dns->bytes_parsed += 2;

    set16(dns->arcount, buffer, length);
    dns->bytes_parsed += 2;

    return OMG_DNS_OK;
}

int omg_dns_build_rr(omg_dns_rr_t* rr, const uint8_t* buffer, size_t length) {
    return OMG_DNS_OK;
}
