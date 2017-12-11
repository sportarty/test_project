#ifndef _ENDPOINT_IPV4_H_
#define _ENDPOINT_IPV4_H_

#include "endpoint.h"
#include <arpa/inet.h>


class endpoint_ipv4 : public endpoint
{
public:
	// конструктор
    endpoint_ipv4(const std::string& ip, std::uint16_t port) noexcept;
    endpoint_ipv4() noexcept;
    ~endpoint_ipv4() noexcept override;
	
	virtual int get_domain() const override;
	virtual int get_type() const override;
	virtual int get_protocol() const override;
    virtual const sockaddr *get_sockaddr() const override;
    virtual const socklen_t* get_sockaddr_len() const override;

private:
    sockaddr_in sa_;
    socklen_t slen_;
};

#endif //_ENDPOINT_IPV4_
