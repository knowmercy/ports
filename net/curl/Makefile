# $OpenBSD: Makefile,v 1.130 2017/10/25 19:31:30 naddy Exp $

COMMENT=	get files from FTP, Gopher, HTTP or HTTPS servers

VERSION=	7.56.1
DISTNAME=	curl-${VERSION}
SHARED_LIBS=	curl                 25.12    # 9.0
CATEGORIES=	net
HOMEPAGE=	https://curl.haxx.se/

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# MIT
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	https://curl.haxx.se/download/ \
		https://execve.home.kg/curl/
EXTRACT_SUFX=	.tar.xz

LIB_DEPENDS=	www/nghttp2
WANTLIB=	c crypto pthread nghttp2 ssl z

SEPARATE_BUILD=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--with-ca-bundle=/etc/ssl/cert.pem \
		--without-libidn2 \
		--without-libpsl \
		--without-libssh2
CONFIGURE_ENV=	ac_cv_path_NROFF="/usr/bin/mandoc -Tascii"

# speed up some time-consuming configure tests
CONFIGURE_ENV+= \
    curl_cv_func_select_args="int,fd_set *,struct timeval *,int" \
    curl_cv_func_recv_args="int,void *,size_t,int,ssize_t" \
    curl_cv_func_send_args="int,const void *,size_t,int,ssize_t" \
    curl_cv_func_getnameinfo_args="const struct sockaddr *,socklen_t,size_t,int"

# Note:
# use ulimit -p 256 for test

.include <bsd.port.mk>
