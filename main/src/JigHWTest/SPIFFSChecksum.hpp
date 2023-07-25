#ifndef BATMOBILE_FIRMWARE_SPIFFSCHECKSUM_H
#define BATMOBILE_FIRMWARE_SPIFFSCHECKSUM_H
struct {
	const char* name;
	uint32_t sum;
} static const SPIFFSChecksums[] PROGMEM = {
		{ "/spiffs/bg.bin",                       1218486 },
		{ "/spiffs/bg_bot.bin",                   1519635 },
		{ "/spiffs/clockIcons/0.bin",             16064 },
		{ "/spiffs/clockIcons/1.bin",             11941 },
		{ "/spiffs/clockIcons/2.bin",             16577 },
		{ "/spiffs/clockIcons/3.bin",             15801 },
		{ "/spiffs/clockIcons/4.bin",             13953 },
		{ "/spiffs/clockIcons/5.bin",             16661 },
		{ "/spiffs/clockIcons/6.bin",             16440 },
		{ "/spiffs/clockIcons/7.bin",             11573 },
		{ "/spiffs/clockIcons/8.bin",             16404 },
		{ "/spiffs/clockIcons/9.bin",             13766 },
		{ "/spiffs/clockIcons/colon.bin",         5912 },
		{ "/spiffs/clockIcons/space.bin",         165 },
		{ "/spiffs/icon/app_inst.bin",            6256 },
		{ "/spiffs/icon/app_mess.bin",            4969 },
		{ "/spiffs/icon/app_sms.bin",             4040 },
		{ "/spiffs/icon/app_snap.bin",            4196 },
		{ "/spiffs/icon/app_tiktok.bin",          3626 },
		{ "/spiffs/icon/app_wapp.bin",            4642 },
		{ "/spiffs/icon/back.bin",                2117 },
		{ "/spiffs/icon/back_sel.bin",            1749 },
		{ "/spiffs/icon/call_in.bin",             2976 },
		{ "/spiffs/icon/call_miss.bin",           2942 },
		{ "/spiffs/icon/call_out.bin",            3091 },
		{ "/spiffs/icon/cat_email.bin",           4165 },
		{ "/spiffs/icon/cat_entert.bin",          5526 },
		{ "/spiffs/icon/cat_fin.bin",             5522 },
		{ "/spiffs/icon/cat_health.bin",          4553 },
		{ "/spiffs/icon/cat_loc.bin",             5878 },
		{ "/spiffs/icon/cat_news.bin",            5272 },
		{ "/spiffs/icon/cat_other.bin",           2754 },
		{ "/spiffs/icon/cat_sched.bin",           4493 },
		{ "/spiffs/icon/cat_soc.bin",             3534 },
		{ "/spiffs/icon/etc.bin",                 2098 },
		{ "/spiffs/icon/lock_closed.bin",         3508 },
		{ "/spiffs/icon/lock_open.bin",           3554 },
		{ "/spiffs/icon/trash.bin",               2454 },
		{ "/spiffs/icon/trash_sel.bin",           2086 },
		{ "/spiffs/icons/batteryFull.bin",        5990 },
		{ "/spiffs/icons/batteryLow.bin",         4674 },
		{ "/spiffs/icons/batteryMid.bin",         4487 },
		{ "/spiffs/icons/bigLowBattery.bin",      23348 },
		{ "/spiffs/icons/phone.bin",              5251 },
		{ "/spiffs/icons/phoneDisconnected.bin",  5026 },
		{ "/spiffs/level/bg.bin",                 557820 },
		{ "/spiffs/level/bubbleCenter.bin",       22561 },
		{ "/spiffs/level/bubbleHorizontal.bin",   17953 },
		{ "/spiffs/level/bubbleVertical.bin",     17720 },
		{ "/spiffs/level/markingsCenter.bin",     6467 },
		{ "/spiffs/level/markingsHorizontal.bin", 3864 },
		{ "/spiffs/level/markingsVertical.bin",   3513 },
		{ "/spiffs/menu/connected/0.bin",         72621 },
		{ "/spiffs/menu/connected/1.bin",         72957 },
		{ "/spiffs/menu/connected/10.bin",        74541 },
		{ "/spiffs/menu/connected/11.bin",        74541 },
		{ "/spiffs/menu/connected/12.bin",        74541 },
		{ "/spiffs/menu/connected/13.bin",        74541 },
		{ "/spiffs/menu/connected/14.bin",        74541 },
		{ "/spiffs/menu/connected/15.bin",        74541 },
		{ "/spiffs/menu/connected/16.bin",        74541 },
		{ "/spiffs/menu/connected/17.bin",        74541 },
		{ "/spiffs/menu/connected/18.bin",        74541 },
		{ "/spiffs/menu/connected/19.bin",        74541 },
		{ "/spiffs/menu/connected/2.bin",         73462 },
		{ "/spiffs/menu/connected/20.bin",        74541 },
		{ "/spiffs/menu/connected/3.bin",         74270 },
		{ "/spiffs/menu/connected/4.bin",         74541 },
		{ "/spiffs/menu/connected/5.bin",         74541 },
		{ "/spiffs/menu/connected/6.bin",         74694 },
		{ "/spiffs/menu/connected/7.bin",         74541 },
		{ "/spiffs/menu/connected/8.bin",         74541 },
		{ "/spiffs/menu/connected/9.bin",         74541 },
		{ "/spiffs/menu/connected/desc.bin",      398 },
		{ "/spiffs/menu/disconnected/0.bin",      72621 },
		{ "/spiffs/menu/disconnected/1.bin",      20921 },
		{ "/spiffs/menu/disconnected/10.bin",     61180 },
		{ "/spiffs/menu/disconnected/11.bin",     64429 },
		{ "/spiffs/menu/disconnected/12.bin",     75962 },
		{ "/spiffs/menu/disconnected/13.bin",     85803 },
		{ "/spiffs/menu/disconnected/14.bin",     89447 },
		{ "/spiffs/menu/disconnected/15.bin",     88359 },
		{ "/spiffs/menu/disconnected/16.bin",     87233 },
		{ "/spiffs/menu/disconnected/17.bin",     94435 },
		{ "/spiffs/menu/disconnected/18.bin",     94969 },
		{ "/spiffs/menu/disconnected/19.bin",     107024 },
		{ "/spiffs/menu/disconnected/2.bin",      33575 },
		{ "/spiffs/menu/disconnected/20.bin",     97646 },
		{ "/spiffs/menu/disconnected/21.bin",     107206 },
		{ "/spiffs/menu/disconnected/22.bin",     106833 },
		{ "/spiffs/menu/disconnected/23.bin",     108429 },
		{ "/spiffs/menu/disconnected/24.bin",     106643 },
		{ "/spiffs/menu/disconnected/25.bin",     86121 },
		{ "/spiffs/menu/disconnected/26.bin",     75360 },
		{ "/spiffs/menu/disconnected/27.bin",     64150 },
		{ "/spiffs/menu/disconnected/28.bin",     38352 },
		{ "/spiffs/menu/disconnected/3.bin",      36292 },
		{ "/spiffs/menu/disconnected/4.bin",      42418 },
		{ "/spiffs/menu/disconnected/5.bin",      43058 },
		{ "/spiffs/menu/disconnected/6.bin",      43302 },
		{ "/spiffs/menu/disconnected/7.bin",      46628 },
		{ "/spiffs/menu/disconnected/8.bin",      48435 },
		{ "/spiffs/menu/disconnected/9.bin",      52369 },
		{ "/spiffs/menu/disconnected/desc.bin",   372 },
		{ "/spiffs/menu/find/0.bin",              79459 },
		{ "/spiffs/menu/find/1.bin",              24096 },
		{ "/spiffs/menu/find/10.bin",             69328 },
		{ "/spiffs/menu/find/11.bin",             78830 },
		{ "/spiffs/menu/find/12.bin",             89342 },
		{ "/spiffs/menu/find/13.bin",             97352 },
		{ "/spiffs/menu/find/14.bin",             94651 },
		{ "/spiffs/menu/find/15.bin",             99286 },
		{ "/spiffs/menu/find/16.bin",             99050 },
		{ "/spiffs/menu/find/17.bin",             107054 },
		{ "/spiffs/menu/find/18.bin",             108949 },
		{ "/spiffs/menu/find/19.bin",             126737 },
		{ "/spiffs/menu/find/2.bin",              39043 },
		{ "/spiffs/menu/find/20.bin",             125863 },
		{ "/spiffs/menu/find/21.bin",             139566 },
		{ "/spiffs/menu/find/22.bin",             137053 },
		{ "/spiffs/menu/find/23.bin",             130190 },
		{ "/spiffs/menu/find/24.bin",             125694 },
		{ "/spiffs/menu/find/25.bin",             91039 },
		{ "/spiffs/menu/find/26.bin",             82015 },
		{ "/spiffs/menu/find/27.bin",             68761 },
		{ "/spiffs/menu/find/28.bin",             40694 },
		{ "/spiffs/menu/find/3.bin",              48160 },
		{ "/spiffs/menu/find/4.bin",              54348 },
		{ "/spiffs/menu/find/5.bin",              62939 },
		{ "/spiffs/menu/find/6.bin",              53093 },
		{ "/spiffs/menu/find/7.bin",              56195 },
		{ "/spiffs/menu/find/8.bin",              56703 },
		{ "/spiffs/menu/find/9.bin",              61679 },
		{ "/spiffs/menu/find/desc.bin",           372 },
		{ "/spiffs/menu/labels/connection.bin",   28975 },
		{ "/spiffs/menu/labels/find.bin",         20949 },
		{ "/spiffs/menu/labels/level.bin",        10379 },
		{ "/spiffs/menu/labels/ringing.bin",      21906 },
		{ "/spiffs/menu/labels/settings.bin",     15322 },
		{ "/spiffs/menu/labels/theremin.bin",     16716 },
		{ "/spiffs/menu/level/0.bin",             29039 },
		{ "/spiffs/menu/level/1.bin",             27161 },
		{ "/spiffs/menu/level/10.bin",            27630 },
		{ "/spiffs/menu/level/11.bin",            27102 },
		{ "/spiffs/menu/level/12.bin",            28661 },
		{ "/spiffs/menu/level/13.bin",            27102 },
		{ "/spiffs/menu/level/14.bin",            27619 },
		{ "/spiffs/menu/level/15.bin",            27529 },
		{ "/spiffs/menu/level/2.bin",             26272 },
		{ "/spiffs/menu/level/3.bin",             28183 },
		{ "/spiffs/menu/level/4.bin",             27292 },
		{ "/spiffs/menu/level/5.bin",             28183 },
		{ "/spiffs/menu/level/6.bin",             26272 },
		{ "/spiffs/menu/level/7.bin",             27161 },
		{ "/spiffs/menu/level/8.bin",             29039 },
		{ "/spiffs/menu/level/9.bin",             27534 },
		{ "/spiffs/menu/level/desc.bin",          289 },
		{ "/spiffs/menu/ring/0.bin",              76801 },
		{ "/spiffs/menu/ring/1.bin",              21219 },
		{ "/spiffs/menu/ring/10.bin",             65650 },
		{ "/spiffs/menu/ring/11.bin",             69348 },
		{ "/spiffs/menu/ring/12.bin",             79524 },
		{ "/spiffs/menu/ring/13.bin",             83220 },
		{ "/spiffs/menu/ring/14.bin",             89623 },
		{ "/spiffs/menu/ring/15.bin",             89644 },
		{ "/spiffs/menu/ring/16.bin",             89281 },
		{ "/spiffs/menu/ring/17.bin",             92453 },
		{ "/spiffs/menu/ring/18.bin",             105795 },
		{ "/spiffs/menu/ring/19.bin",             121124 },
		{ "/spiffs/menu/ring/2.bin",              34913 },
		{ "/spiffs/menu/ring/20.bin",             115712 },
		{ "/spiffs/menu/ring/21.bin",             121561 },
		{ "/spiffs/menu/ring/22.bin",             117374 },
		{ "/spiffs/menu/ring/23.bin",             115698 },
		{ "/spiffs/menu/ring/24.bin",             111112 },
		{ "/spiffs/menu/ring/25.bin",             90542 },
		{ "/spiffs/menu/ring/26.bin",             79709 },
		{ "/spiffs/menu/ring/27.bin",             67689 },
		{ "/spiffs/menu/ring/28.bin",             40371 },
		{ "/spiffs/menu/ring/29.bin",             79656 },
		{ "/spiffs/menu/ring/3.bin",              39689 },
		{ "/spiffs/menu/ring/30.bin",             79658 },
		{ "/spiffs/menu/ring/31.bin",             79658 },
		{ "/spiffs/menu/ring/32.bin",             77579 },
		{ "/spiffs/menu/ring/4.bin",              42552 },
		{ "/spiffs/menu/ring/5.bin",              46137 },
		{ "/spiffs/menu/ring/6.bin",              46219 },
		{ "/spiffs/menu/ring/7.bin",              53253 },
		{ "/spiffs/menu/ring/8.bin",              55301 },
		{ "/spiffs/menu/ring/9.bin",              58342 },
		{ "/spiffs/menu/ring/desc.bin",           418 },
		{ "/spiffs/menu/settings/0.bin",          31787 },
		{ "/spiffs/menu/settings/1.bin",          30843 },
		{ "/spiffs/menu/settings/10.bin",         29618 },
		{ "/spiffs/menu/settings/11.bin",         29422 },
		{ "/spiffs/menu/settings/12.bin",         30248 },
		{ "/spiffs/menu/settings/13.bin",         31186 },
		{ "/spiffs/menu/settings/2.bin",          31400 },
		{ "/spiffs/menu/settings/3.bin",          30741 },
		{ "/spiffs/menu/settings/4.bin",          29892 },
		{ "/spiffs/menu/settings/5.bin",          29917 },
		{ "/spiffs/menu/settings/6.bin",          29506 },
		{ "/spiffs/menu/settings/7.bin",          28447 },
		{ "/spiffs/menu/settings/8.bin",          30130 },
		{ "/spiffs/menu/settings/9.bin",          30138 },
		{ "/spiffs/menu/settings/desc.bin",       202 },
		{ "/spiffs/menu/theremin/0.bin",          25058 },
		{ "/spiffs/menu/theremin/1.bin",          26177 },
		{ "/spiffs/menu/theremin/2.bin",          29154 },
		{ "/spiffs/menu/theremin/3.bin",          29462 },
		{ "/spiffs/menu/theremin/4.bin",          32035 },
		{ "/spiffs/menu/theremin/5.bin",          38830 },
		{ "/spiffs/menu/theremin/6.bin",          30721 },
		{ "/spiffs/menu/theremin/7.bin",          30608 },
		{ "/spiffs/menu/theremin/desc.bin",       163 },
		{ "/spiffs/theremin/dot.bin",             2083 },
		{ "/spiffs/theremin/down.bin",            3497 },
		{ "/spiffs/theremin/horizontalBar.bin",   66841 },
		{ "/spiffs/theremin/left.bin",            3483 },
		{ "/spiffs/theremin/right.bin",           3585 },
		{ "/spiffs/theremin/up.bin",              3265 },
		{ "/spiffs/theremin/verticalBar.bin",     45154 }
};

#endif //BATMOBILE_FIRMWARE_SPIFFSCHECKSUM_H
