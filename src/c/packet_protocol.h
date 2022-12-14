/* Header for jnetpcap_utils utility methods */

#ifndef _Included_jnetpcap_packet_protocol_h
#define _Included_jnetpcap_packet_protocol_h
#ifdef __cplusplus

#include <stdint.h>

#include "export.h"
#include <jni.h>
#include "nio_jbuffer.h"
#include "org_jnetpcap_protocol_JProtocol.h"
#include "org_jnetpcap_packet_JScan.h"

#define END_OF_HEADERS   org_jnetpcap_packet_JScan_END_OF_HEADERS_ID
#define ETHERNET_ID      org_jnetpcap_protocol_JProtocol_ETHERNET_ID
#define TCP_ID           org_jnetpcap_protocol_JProtocol_TCP_ID
#define UDP_ID           org_jnetpcap_protocol_JProtocol_UDP_ID
#define IEEE_802DOT3_ID  org_jnetpcap_protocol_JProtocol_IEEE_802DOT3_ID
#define IEEE_802DOT2_ID  org_jnetpcap_protocol_JProtocol_IEEE_802DOT2_ID
#define IEEE_SNAP_ID     org_jnetpcap_protocol_JProtocol_IEEE_SNAP_ID
#define IP4_ID           org_jnetpcap_protocol_JProtocol_IP4_ID
#define IP6_ID           org_jnetpcap_protocol_JProtocol_IP6_ID
#define IEEE_802DOT1Q_ID org_jnetpcap_protocol_JProtocol_IEEE_802DOT1Q_ID
#define L2TP_ID          org_jnetpcap_protocol_JProtocol_L2TP_ID
#define PPP_ID           org_jnetpcap_protocol_JProtocol_PPP_ID
#define ICMP_ID          org_jnetpcap_protocol_JProtocol_ICMP_ID
#define HTTP_ID          org_jnetpcap_protocol_JProtocol_HTTP_ID
#define HTML_ID          org_jnetpcap_protocol_JProtocol_HTML_ID
#define ARP_ID           org_jnetpcap_protocol_JProtocol_ARP_ID
#define SIP_ID           org_jnetpcap_protocol_JProtocol_SIP_ID
#define SDP_ID           org_jnetpcap_protocol_JProtocol_SDP_ID
#define RTP_ID           org_jnetpcap_protocol_JProtocol_RTP_ID
#define SLL_ID           org_jnetpcap_protocol_JProtocol_SLL_ID

#define SCTP_ID              org_jnetpcap_protocol_JProtocol_SCTP_ID
#define SCTP_CHUNK_ID        org_jnetpcap_protocol_JProtocol_SCTP_DATA_ID
#define SCTP_DATA_ID         org_jnetpcap_protocol_JProtocol_SCTP_DATA_ID
#define SCTP_INIT_ID         org_jnetpcap_protocol_JProtocol_SCTP_INIT_ID
#define SCTP_INIT_ACK_ID     org_jnetpcap_protocol_JProtocol_SCTP_INIT_ACK_ID
#define SCTP_SACK_ID         org_jnetpcap_protocol_JProtocol_SCTP_SACK_ID
#define SCTP_HEARTBEAT_ID    org_jnetpcap_protocol_JProtocol_SCTP_HEARTBEAT_ID
#define SCTP_HEARTBEAT_ACK_ID    org_jnetpcap_protocol_JProtocol_SCTP_HEARTBEAT_ACK_ID
#define SCTP_ABORT_ID        org_jnetpcap_protocol_JProtocol_SCTP_ABORT_ID
#define SCTP_SHUTDOWN_ID     org_jnetpcap_protocol_JProtocol_SCTP_SHUTDOWN_ID
#define SCTP_SHUTDOWN_ACK_ID org_jnetpcap_protocol_JProtocol_SCTP_SHUTDOWN_ACK_ID
#define SCTP_ERROR_ID        org_jnetpcap_protocol_JProtocol_SCTP_ERROR_ID
#define SCTP_COOKIE_ID       org_jnetpcap_protocol_JProtocol_SCTP_COOKIE_ID
#define SCTP_COOKIE_ACK_ID   org_jnetpcap_protocol_JProtocol_SCTP_COOKIE_ACK_ID
#define SCTP_ECNE_ID         org_jnetpcap_protocol_JProtocol_SCTP_ECNE_ID
#define SCTP_CWR_ID          org_jnetpcap_protocol_JProtocol_SCTP_CWR_ID
#define SCTP_SHUTDOWN_COMPLETE_ID org_jnetpcap_protocol_JProtocol_SCTP_SHUTDOWN_COMPLETE_ID

#define RTCP_ID 		org_jnetpcap_protocol_JProtocol_RTCP_SENDER_REPORT_ID
#define RTCP_CHUNK_ID 		org_jnetpcap_protocol_JProtocol_RTCP_SENDER_REPORT_ID
#define RTCP_SENDER_REPORT_ID org_jnetpcap_protocol_JProtocol_RTCP_SENDER_REPORT_ID
#define RTCP_RECEIVER_REPORT_ID org_jnetpcap_protocol_JProtocol_RTCP_RECEIVER_REPORT_ID
#define RTCP_SDES_ID org_jnetpcap_protocol_JProtocol_RTCP_SDES_ID
#define RTCP_BYE_ID org_jnetpcap_protocol_JProtocol_RTCP_BYE_ID
#define RTCP_APP_ID org_jnetpcap_protocol_JProtocol_RTCP_APP_ID

#define NULL_HEADER_ID org_jnetpcap_protocol_JProtocol_NULL_HEADER_ID

#define WEB_IMAGE_ID        org_jnetpcap_protocol_JProtocol_WEB_IMAGE_ID

#define NETBIOS_ID END_OF_HEADERS

typedef struct null_header_ {

	uint32_t	type; // PF_ protocol family type

} null_header_t;

#define SCTP_DATA_FLAG_LAST_SEG		0x01
#define SCTP_DATA_FLAG_FIRST_SEG	0x02
#define SCTP_DATA_FLAG_ORDERED		0x04
#define SCTP_DATA_FLAG_DELAY		0x08
/**
 * SCTP Chunk
 */
typedef struct sctp_chunk_ {

	uint8_t		type;
	uint8_t		flags;
	uint16_t	length;

} sctp_chunk_t;

#define SCTP_LEN	12
/**
 * Stream Control Transport Protocol
 */
typedef struct sctp_ {

	uint16_t	sport;
	uint16_t	dport;
	uint32_t	tag;
	uint32_t	crc32;

} sctp_t;

/*
 * Linux Socket Cooked Capture header - a pseudo header as DL substitute
 */
#define SLL_LEN	16		          // total header length
#define SLL_ADDR_LEN	8		      // length of address field

typedef struct sll_t {
	uint16_t	sll_pkttype;	          // packet type
	uint16_t	sll_hatype;	            // link-layer address type
	uint16_t	sll_halen;	            // link-layer address length
	uint8_t		sll_addr[SLL_ADDR_LEN];	// link-layer address
	uint16_t	sll_protocol;         	// protocol
} sll_t;

/*
 * Realtime Transfer Protocol and extension
 */
#define RTP_LENGTH	12
#define RTPX_LENGTH	4

typedef struct rtpx_t {
	
	uint16_t	rtpx_profile; 	// Profile specific
	uint16_t	rtpx_len;		// Length of extension header
	
} rtpx_t;

/*
 *  RTP and RTCP family of protocols
 *  See RFC3550
 */

/**
 * RTCP SSRC Sender Report (section 3 of the header)
 */
typedef struct rtcp_ssrc_ {
	uint32_t	ssrc_id; // SSRC identifier of the source
	uint32_t	ssrc_fract_loss:8; // Fraction of RTP data lost
	uint32_t	ssrc_total_loss:24; // Cumulative of RTP data lost
	uint32_t	ssrc_high_seq; // Extended highest seq received
	uint32_t	ssrc_jitter; // Interarrival Jitter
	uint32_t	ssrc_lsr; // Last SR timestamp
	uint32_t	ssrc_dlsr; // Delay since last SR

} rtcp_ssrc_t;

/*
 * RTCP Sender Report (SR)
 * (Section 2 of the header)
 */
typedef struct rtcp_sr_ {

	uint64_t	sr_ntp; // NTP timestamp
	uint32_t	sr_pkt_count; // Sender's packet count
	uint32_t	sr_octet_count; // Sender's octet count

} rtcp_sr_t;

/*
 * RTCP - main static header present in every RTCP packet.
 * RTCP packets are always on odd port number, while RTP on even (see RFC3550)
 * (Section 1 of the header)
 */
typedef struct rtcp_ {

#  if __BYTE_ORDER == __LITTLE_ENDIAN
	uint8_t 	rtcp_rc:5; // Reception Report Count (RC)
	uint8_t 	rtcp_pad:1;
	uint8_t		rtcp_ver:2; // Must be 2

#  elif __BYTE_ORDER == __BIG_ENDIAN
	uint8_t		rtcp_ver:2; // Must be 2
	uint8_t 	rtcp_pad:1;
	uint8_t 	rtcp_rc:5; // Reception Report Count (RC)

#  else
#   error "Adjust your <bits/endian.h> defines"
#  endif

	uint8_t		rtcp_type; // SR==200, RR==201
	uint16_t	rtcp_len;  // 32-bit word count (including header -1)
	uint32_t	rtcp_ssrc; // Synchronization source ID

} rtcp_t;


typedef struct rtp_t {

#  if __BYTE_ORDER == __LITTLE_ENDIAN
	uint8_t 	rtp_cc:4;
	uint8_t 	rtp_ext:1;
	uint8_t 	rtp_pad:1;
	uint8_t		rtp_ver:2;
	
	uint8_t		rtp_type:7;
	uint8_t		rtp_marker:1;
	
#  elif __BYTE_ORDER == __BIG_ENDIAN
	uint8_t		rtp_ver:2;
	uint8_t 	rtp_pad:1;
	uint8_t 	rtp_ext:1;
	uint8_t 	rtp_cc:4;
	
	uint8_t		rtp_marker:1;
	uint8_t		rtp_type:7;
	
#  else
#   error "Adjust your <bits/endian.h> defines"
#  endif
	
	uint16_t	rtp_seq;
	uint32_t	rtp_ts;
	uint32_t	rtp_ssrc;

} rtp_t;


/*
 * Address Resulution Protocol
 */
typedef struct arp_t {
	uint16_t htype;
	uint16_t ptype;
	uint8_t  hlen;
	uint8_t  plen;
} arp_t;


/*
 * Internet Control Message Protocol
 */
typedef struct icmp_t {
	uint8_t type;
	uint8_t code;
	uint16_t crc;

} icmp_t;

/*
 * Point to Point Protocol
 */
typedef struct ppp_t {
	uint8_t addr;
	uint8_t control;
	uint16_t protocol;
} ppt_t;

/*
 * Layer 2 tunneling protocol
 */
typedef struct l2tp_t {
#  if __BYTE_ORDER == __LITTLE_ENDIAN
	uint16_t p :1;
	uint16_t o :1;
	uint16_t res2 :1;
	uint16_t s :1;
	uint16_t res1 :2;
	uint16_t l :1;
	uint16_t t :1;
	uint16_t version :4;
	uint16_t res3 :4;
#  elif __BYTE_ORDER == __BIG_ENDIAN
	uint16_t t:1;
	uint16_t l:1;
	uint16_t res1:2;
	uint16_t s:1;
	uint16_t res2:1;
	uint16_t o:1;
	uint16_t p:1;
	uint16_t res3:4;
	uint16_t version:4;
#  else
#   error "Adjust your <bits/endian.h> defines"
#  endif

} l2tp_t;

/*
 * IEEE 802.1q VLAN header
 */
typedef struct vlan_t {
	uint16_t priority :3;
	uint16_t cfi :1;
	uint16_t id :12;

	uint16_t type;
} vlan_t;

/**
 * SNAP IEEE
 */
typedef union snap_t {
	uint32_t oui :24;
	struct {
		uint16_t reserved[1];
		uint16_t pid;
	};
} snap_t;

/**
 * LLC IEEE802.2
 */
typedef struct llc_t {
	uint8_t dsap;
	uint8_t ssap;
	uint8_t control;
	union {
		uint8_t info;
	} ucontrol;
} llc_t;

/**
 * UDP structure
 */
typedef struct udp_t {
	uint16_t sport;
	uint16_t dport;
	uint16_t length;
	uint16_t checksum;

} udp_t;

/**
 * TCP structure
 */
typedef struct tcp_t {
	uint16_t sport;
	uint16_t dport;
	uint32_t seq;
	uint32_t ack_seq;
#  if __BYTE_ORDER == __LITTLE_ENDIAN
	uint16_t res1 :4;
	uint16_t doff :4;
	uint16_t fin :1;
	uint16_t syn :1;
	uint16_t rst :1;
	uint16_t psh :1;
	uint16_t ack :1;
	uint16_t urg :1;
	uint16_t res2 :2;
#  elif __BYTE_ORDER == __BIG_ENDIAN
	uint16_t doff:4;
	uint16_t res1:4;
	uint16_t res2:2;
	uint16_t urg:1;
	uint16_t ack:1;
	uint16_t psh:1;
	uint16_t rst:1;
	uint16_t syn:1;
	uint16_t fin:1;
#  else
#   error "Adjust your <bits/endian.h> defines"
#  endif
	uint16_t window;
	uint16_t check;
	uint16_t urg_ptr;
} tcp_t;

#define PROTO_ETHERNET_HEADER_LENGTH 14
#define PROTO_802_3_MAX_LEN 0x600

/**
 * Ethernet 2 structure
 */
typedef struct ethernet_t {
	uint8_t dhost[6]; /* destination eth addr */
	uint8_t shost[6]; /* destination eth addr */
	uint16_t type; /* destination eth addr */
} ethernet_t;

/**
 * IP v6 structure
 * RFC 1883
 */
typedef struct ip6 {
	union {
		struct ip6_hdrctl {
			uint32_t ip6_un1_flow;	/* 20 bits of flow-ID */
			uint16_t ip6_un1_plen;	/* payload length */
			uint8_t  ip6_un1_nxt;	/* next header */
			uint8_t  ip6_un1_hlim;	/* hop limit */
		} ip6_un1;
		uint8_t ip6_un2_vfc;	/* 4 bits version, 4 bits class */
	} ip6_ctlun;
	uint8_t ip6_src[16];	/* source address */
	uint8_t ip6_dst[16];	/* destination address */
} ip6_t;

#define ip6_vfc		ip6_ctlun.ip6_un2_vfc
#define ip6_flow	ip6_ctlun.ip6_un1.ip6_un1_flow
#define ip6_plen	ip6_ctlun.ip6_un1.ip6_un1_plen
#define ip6_nxt		ip6_ctlun.ip6_un1.ip6_un1_nxt
#define ip6_hlim	ip6_ctlun.ip6_un1.ip6_un1_hlim
#define ip6_hops	ip6_ctlun.ip6_un1.ip6_un1_hlim

#define IP6_HEADER_LENGTH 40

#define IP6_OPT_HOP_BY_HOP 		0
#define IP6_OPT_DEST_OPTIONS	60
#define IP6_OPT_ROUTING_HEADER	43
#define IP6_OPT_FRAGMENT_HEADER	44
#define IP6_OPT_AUTH_HEADER		51
#define IP6_OPT_SECURITY_HEADER	50
#define IP6_OPT_MOBILITY_HEADER	135
#define IP6_OPT_NO_NEXT_HEADER	59

/**
 * IP v4 structure
 */
typedef struct ip4 {
#if __BYTE_ORDER == __LITTLE_ENDIAN
	unsigned int ihl :4;
	unsigned int version :4;
#elif __BYTE_ORDER == __BIG_ENDIAN
	unsigned int version:4;
	unsigned int ihl:4;
#else
# error "Please fix <bits/endian.h>"
#endif
	uint8_t tos;
	uint16_t tot_len;
	uint16_t id;
	uint16_t frag_off; // flags=3 bits, offset=13 bits
	uint8_t ttl;
	uint8_t protocol;
	uint16_t check;
	uint32_t saddr;
	uint32_t daddr;
    // Note if there are issues running this on windows - may need to uncomment below and comment above. This
    // uint types have padding applied to it which may cause weird offsets when referencing memory locations in memory.

//    unsigned int tos:8;
//    unsigned int tot_len:16; //works
//    unsigned int id:16;
//    unsigned int frag_off:16;
//    unsigned int ttl:8;
//    unsigned int protocol:8;
//    unsigned int check:16;
//    unsigned int saddr:32;
//    unsigned int daddr:32;
	/*The options start here. */
} ip4_t;

#define IP4_FLAGS_MASK 0xE000
#define IP4_FRAG_OFF_MASK ~IP4_FLAGS_MASK
#define IP4_FLAG_MF 0x2000
#define IP4_FLAG_DF 0x4000
#define IP4_FLAG_RESERVED 0x8000


/****************************************************************
 * **************************************************************
 * 
 * Scanner's native and java per protocol prototypes
 * 
 * **************************************************************
 ****************************************************************/

int lookup_ethertype(uint16_t type);
//
//void scan_ethernet (scan_t *scan);
//void scan_ip4      (scan_t *scan);


#endif
#endif
