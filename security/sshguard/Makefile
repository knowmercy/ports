# $OpenBSD: Makefile,v 1.10 2017/05/27 19:57:06 ajacoutot Exp $

COMMENT=	protect against brute force attacks on sshd and others

DISTNAME=	sshguard-1.5
REVISION=	3
CATEGORIES=	security

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB+=	c pthread

HOMEPAGE=	http://www.sshguard.net/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sshguard/}
EXTRACT_SUFX=	.tar.bz2

CONFIGURE_STYLE=gnu
NO_TEST=	Yes

CONFIGURE_ARGS = --with-firewall=pf 

.include <bsd.port.mk>
