# $OpenBSD: Makefile.inc,v 1.8 2017/07/28 10:50:45 sthen Exp $

CATEGORIES ?=		textproc x11
MASTER_SITES ?=		https://pwmt.org/projects/zathura/plugins/download/

# MIT
PERMIT_PACKAGE_CDROM ?=	Yes

RUN_DEPENDS ?=	devel/desktop-file-utils \
		textproc/zathura/core
LIB_DEPENDS +=	x11/girara
BUILD_DEPENDS ?=	textproc/zathura/core

MAKE_FLAGS ?=	VERBOSE=1 \
		DESKTOPPREFIX=${PREFIX}/share/applications

NO_TEST ?=	Yes
USE_GMAKE ?=	Yes

COMPILER ?=	gcc
COMPILER_LANGS ?= c
