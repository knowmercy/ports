# $OpenBSD: Makefile,v 1.33 2017/11/04 21:48:06 naddy Exp $

COMMENT-main=	fast, light and extensible chat client
COMMENT-lua=	Lua bindings for weechat
COMMENT-python=	Python bindings for weechat
COMMENT-ruby=	Ruby bindings for weechat
COMMENT-tcl=	Tcl bindings for weechat

V=		1.9.1
DISTNAME=	weechat-${V}

PKGNAME-main=	weechat-${V}
PKGNAME-lua=	weechat-lua-${V}
PKGNAME-python=	weechat-python-${V}
PKGNAME-ruby=	weechat-ruby-${V}
PKGNAME-tcl=	weechat-tcl-${V}

REVISION-main=	0
REVISION-ruby=	0

CATEGORIES=	net

HOMEPAGE=	https://www.weechat.org/
MAINTAINER=	Daniel Jakots <obsd@chown.me>

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	${HOMEPAGE}/files/src/

MULTI_PACKAGES=	-main -lua -python -ruby -tcl

WANTLIB-main=	c curl iconv intl m ncursesw perl pthread \
		gcrypt gnutls gpg-error z

WANTLIB-lua=	${MODLUA_WANTLIB} m
WANTLIB-python=	${MODPY_WANTLIB}
WANTLIB-ruby=	${MODRUBY_WANTLIB}
WANTLIB-tcl=	${MODTCL_WANTLIB}

MODULES=	devel/cmake \
		lang/lua \
		lang/python \
		lang/ruby \
		lang/tcl

MODLUA_RUNDEP=	No
MODPY_RUNDEP=	No
MODRUBY_RUNDEP=	No

BUILD_DEPENDS=	devel/gettext-tools

LIB_DEPENDS=	devel/gettext \
		security/libgcrypt \
		security/gnutls \
		net/curl

LIB_DEPENDS-lua=	${MODLUA_LIB_DEPENDS}
RUN_DEPENDS-lua=	net/weechat,-main ${MODLUA_RUN_DEPENDS}

LIB_DEPENDS-python=	${MODPY_LIB_DEPENDS}
RUN_DEPENDS-python=	net/weechat,-main ${MODPY_RUN_DEPENDS}

LIB_DEPENDS-ruby=	${MODRUBY_LIB_DEPENDS}
RUN_DEPENDS-ruby=	net/weechat,-main ${MODRUBY_RUN_DEPENDS}

LIB_DEPENDS-tcl=	${MODTCL_LIB_DEPENDS}
RUN_DEPENDS-tcl=	net/weechat,-main ${MODTCL_RUN_DEPENDS}

CONFIGURE_ARGS+=-DENABLE_ASPELL=no \
		-DENABLE_GUILE=no \
		-DENABLE_RUBY=yes \
		-DENABLE_LUA=yes \
		-DENABLE_TCL=yes \
		-DENABLE_PYTHON=yes \
		-DENABLE_JAVASCRIPT=no \
		-DHAVE_BACKTRACE=no \
		-DCA_FILE=/etc/ssl/cert.pem \
		-DTCL_TCLSH=${MODTCL_BIN} \
		-DTCL_INCLUDE_PATH=${MODTCL_INCDIR} \
		-DMODTCL_LIB=${MODTCL_LIB}

pre-configure:
	rm -f ${WRKSRC}/cmake/FindLua.cmake \
		${WRKSRC}/cmake/FindRuby.cmake \
		${WRKSRC}/cmake/FindTCL.cmake

post-install:
	$(INSTALL_DATA_DIR) ${PREFIX}/share/doc/weechat
	$(INSTALL_DATA) $(WRKSRC)/doc/en/weechat_*.en.adoc \
	${PREFIX}/share/doc/weechat/

NO_TEST=	Yes

.include <bsd.port.mk>
