# $OpenBSD: Makefile,v 1.73 2017/10/30 22:19:38 sthen Exp $

COMMENT=	Berkeley Internet Name Daemon: DNS server and tools

V=		9.10.6
REVISION=	0

DISTNAME=	bind-$V
PKGNAME=	isc-bind-${V:S/-P/pl/}

SHARED_LIBS +=  isc                  3.4      # 190.0
SHARED_LIBS +=  isccc                0.0      # 140.5
SHARED_LIBS +=  dns                  5.0      # 190.1
SHARED_LIBS +=  isccfg               0.4      # 144.0
SHARED_LIBS +=  bind9                0.1      # 141.0
SHARED_LIBS +=  lwres                0.1      # 141.3
SHARED_LIBS +=  irs                  0.0      # 141.7

# not installed:
#SHARED_LIBS += isc-nosymtbl         190.0    # 190.0
#SHARED_LIBS +=	t_api                0.0      # unknown

CATEGORIES=	net

HOMEPAGE=	http://www.isc.org/software/bind

MAINTAINER=	Stuart Henderson <sthen@openbsd.org>

# ISC
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	c iconv json-c lzma m pthread xml2 z

MASTER_SITES=	${MASTER_SITE_ISC:=bind9/$V/}

MODULES=	lang/python
# used for dnssec-checkds/dnssec-coverage, but don't want to force the run dep.
# XXX subpackage?
MODPY_RUNDEP=	No
LIB_DEPENDS=	converters/libiconv \
		devel/json-c \
		textproc/libxml

SEPARATE_BUILD=	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS=	--enable-filter-aaaa \
		--enable-threads \
		--with-libtool \
		--with-randomdev=/dev/random \
		--without-readline \
		--with-python=${MODPY_BIN}

CONFIGURE_ENV=	STD_CDEFINES="-DDIG_SIGCHASE=1"

.include <bsd.port.arch.mk>

# we don't link with libgcc, use the c++abi unwinder instead
.if ${PROPERTIES:Mclang}
MAKE_FLAGS +=	UNWINDERLIB=-lc++abi
WANTLIB +=	c++abi
.endif

FAKE_FLAGS=	sysconfdir=${PREFIX}/share/examples/bind9

FLAVORS=	geoip no_ssl
FLAVOR?=
.if ${FLAVOR:Mgeoip}
CONFIGURE_ARGS+= --with-geoip
LIB_DEPENDS+=	net/GeoIP
WANTLIB+=	GeoIP
.endif

.if ${FLAVOR:Mno_ssl}
CONFIGURE_ARGS+= --without-openssl
.else
WANTLIB+=	crypto
.endif

# not strictly speaking interactive, but it configures temporary addresses on
# lo0 as root, so let's try and avoid running it unintentionally
TEST_IS_INTERACTIVE= Yes

pre-test:
	cd ${WRKSRC}/bin/tests/system && ${SUDO} ./ifconfig.sh up

post-test:
	cd ${WRKSRC}/bin/tests/system && ${SUDO} ./ifconfig.sh down

post-install:
	cd ${FILESDIR}; ${INSTALL_DATA} localhost loopback loopback6.arpa \
	    named.conf root.hint ${PREFIX}/share/examples/bind9/

.include <bsd.port.mk>
