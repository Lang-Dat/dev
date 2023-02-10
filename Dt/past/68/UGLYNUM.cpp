/**
 *	author : Lăng Trọng Đạt
 *	creater: 31-01-2023 21:02:55
**/
#include <iostream>
#include <algorithm>
using namespace std;

bool phan_tich(uint64_t n) {
    while (n % 2 == 0)
        n /= 2;
    while (n % 3 == 0)
        n /= 3;
    while (n % 5 == 0)
        n /= 5;
    return n == 1;
}

int ans[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27, 30, 32, 36, 40, 45, 48, 50, 54, 60, 64, 72, 75, 80, 81, 90, 96, 100, 108, 120, 125, 128, 135, 144, 150, 160, 162, 180, 192, 200, 216, 225, 240, 243, 250, 256, 270, 288, 300, 320, 324, 360, 375, 384, 400, 405, 432, 450, 480, 486, 500, 512, 540, 576, 600, 625, 640, 648, 675, 720, 729, 750, 768, 800, 810, 864, 900, 960, 972, 1000, 1024, 1080, 1125, 1152, 1200, 1215, 1250, 1280, 1296, 1350, 1440, 1458, 1500, 1536, 1600, 1620, 1728, 1800, 1875, 1920, 1944, 2000, 2025, 2048, 2160, 2187, 2250, 2304, 2400, 2430, 2500, 2560, 2592, 2700, 2880, 2916, 3000, 3072, 3125, 3200, 3240, 3375, 3456, 3600, 3645, 3750, 3840, 3888, 4000, 4050, 4096, 4320, 4374, 4500, 4608, 4800, 4860, 5000, 5120, 5184, 5400, 5625, 5760, 5832, 6000, 6075, 6144, 6250, 6400, 6480, 6561, 6750, 6912, 7200, 7290, 7500, 7680, 7776, 8000, 8100, 8192, 8640, 8748, 9000, 9216, 9375, 9600, 9720, 10000, 10125, 10240, 10368, 10800, 10935, 11250, 11520, 11664, 12000, 12150, 12288, 12500, 12800, 12960, 13122, 13500, 13824, 14400, 14580, 15000, 15360, 15552, 15625, 16000, 16200, 16384, 16875, 17280, 17496, 18000, 18225, 18432, 18750, 19200, 19440, 19683, 20000, 20250, 20480, 20736, 21600, 21870, 22500, 23040, 23328, 24000, 24300, 24576, 25000, 25600, 25920, 26244, 27000, 27648, 28125, 28800, 29160, 30000, 30375, 30720, 31104, 31250, 32000, 32400, 32768, 32805, 33750, 34560, 34992, 36000, 36450, 36864, 37500, 38400, 38880, 39366, 40000, 40500, 40960, 41472, 43200, 43740, 45000, 46080, 46656, 46875, 48000, 48600, 49152, 50000, 50625, 51200, 51840, 52488, 54000, 54675, 55296, 56250, 57600, 58320, 59049, 60000, 60750, 61440, 62208, 62500, 64000, 64800, 65536, 65610, 67500, 69120, 69984, 72000, 72900, 73728, 75000, 76800, 77760, 78125, 78732, 80000, 81000, 81920, 82944, 84375, 86400, 87480, 90000, 91125, 92160, 93312, 93750, 96000, 97200, 98304, 98415, 100000, 101250, 102400, 103680, 104976, 108000, 109350, 110592, 112500, 115200, 116640, 118098, 120000, 121500, 122880, 124416, 125000, 128000, 129600, 131072, 131220, 135000, 138240, 139968, 140625, 144000, 145800, 147456, 150000, 151875, 153600, 155520, 156250, 157464, 160000, 162000, 163840, 164025, 165888, 168750, 172800, 174960, 177147, 180000, 182250, 184320, 186624, 187500, 192000, 194400, 196608, 196830, 200000, 202500, 204800, 207360, 209952, 216000, 218700, 221184, 225000, 230400, 233280, 234375, 236196, 240000, 243000, 245760, 248832, 250000, 253125, 256000, 259200, 262144, 262440, 270000, 273375, 276480, 279936, 281250, 288000, 291600, 294912, 295245, 300000, 303750, 307200, 311040, 312500, 314928, 320000, 324000, 327680, 328050, 331776, 337500, 345600, 349920, 354294, 360000, 364500, 368640, 373248, 375000, 384000, 388800, 390625, 393216, 393660, 400000, 405000, 409600, 414720, 419904, 421875, 432000, 437400, 442368, 450000, 455625, 460800, 466560, 468750, 472392, 480000, 486000, 491520, 492075, 497664, 500000, 506250, 512000, 518400, 524288, 524880, 531441, 540000, 546750, 552960, 559872, 562500, 576000, 583200, 589824, 590490, 600000, 607500, 614400, 622080, 625000, 629856, 640000, 648000, 655360, 656100, 663552, 675000, 691200, 699840, 703125, 708588, 720000, 729000, 737280, 746496, 750000, 759375, 768000, 777600, 781250, 786432, 787320, 800000, 810000, 819200, 820125, 829440, 839808, 843750, 864000, 874800, 884736, 885735, 900000, 911250, 921600, 933120, 937500};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./UGLYNUM.INP", "r", stdin);
    freopen("./UGLYNUM.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;

    std::cout << ans[n - 1] << "";
    return 0;
}