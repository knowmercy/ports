# $OpenBSD: Makefile,v 1.7 2017/05/31 08:08:16 espie Exp $

COMMENT-main =	graphical sdl rogue-like game
COMMENT-data =	data for Tales of Maj'Eyal

# '

V =		1.5.1
PKGNAME-main =	tome4-${V}
PKGNAME-data =	tome4-data-${V}
CATEGORIES =	games x11

MASTER_SITES =	http://te4.org/dl/t-engine/ \
		http://distfiles-openbsd.perso.pw/
DISTNAME =	t-engine4-src-${V}
EXTRACT_SUFX =	.tar.bz2
HOMEPAGE =	http://te4.org

MULTI_PACKAGES =-main -data

MAINTAINER =	Solene Rapenne <solene@perso.pw>

# GPLV3+ and bundled MIT, zlib, BSD in games/thirdparty/licenses/
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB-main =	GL GLU SDL2 SDL2_image SDL2_ttf openal c m \
		png pthread vorbisfile

BUILD_DEPENDS =	devel/premake4

LIB_DEPENDS-main =	devel/sdl2 \
			devel/sdl2-image \
			devel/sdl2-ttf \
			audio/libvorbis \
			audio/openal

RUN_DEPENDS-main =	games/tome4,-data

LIB_DEPENDS-data =
WANTLIB-data =

COMPILER =	gcc
COMPILER_LANGS =	c


NO_TEST =	Yes

USE_GMAKE =	Yes
MAKE_FLAGS =	verbose=1 CC='${CC}'
MAKE_ENV =	config=release

GAMEDIR =	${PREFIX}/share/tome4
SUBST_VARS +=	GAMEDIR V

# The build system hardcodes the use of the "gcc" command
do-configure:
	sed -i 's/gcc /${CC} /g' ${WRKSRC}/build/te4core.lua
	${SUBST_CMD} ${WRKSRC}/src/getself.c
	${SUBST_CMD} ${WRKSRC}/premake4.lua
	@cd ${WRKSRC} ; premake4 gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/t-engine ${PREFIX}/bin/tome4
	${INSTALL_DATA_DIR} ${GAMEDIR}
	cd ${WRKSRC}; tar cf - bootstrap game | tar xf - -C ${GAMEDIR}
	rm -R ${GAMEDIR}/game/modules/example*
	rm ${GAMEDIR}/bootstrap/boot.lua.orig

.include <bsd.port.mk>
