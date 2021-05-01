#ifndef __VERSION_H
#define __VERSION_H

#define MAIN_VERSION        0.0.1(T)

#define SOFTWARE_NAME       "joke+"
#define COPYRIGHT           "Copyleft 2021-2022, Zhijun Hong"

#define _STR_(s)            #s
#define __STR(s)            _STR_(s)

#define BUILD_VERSION       _STR_(514264M)
#define SOFTWARE_VERSION    __STR(MAIN_VERSION)

#if QT_NO_DEBUG
#define SOFTWARE_TITLE      (SOFTWARE_NAME " V" SOFTWARE_VERSION)
#else
#define SOFTWARE_TITLE      (SOFTWARE_NAME " V" SOFTWARE_VERSION \
                            " (Build " BUILD_VERSION "-Debug)")
#endif

#endif
