#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

void o_0ac21796596e2991c1a5012561a26c72() {
  printf("\x65"
    "r\162n\x6F"
    ":\040%\x64"
    " \054 \x25"
    "s\012", errno, strerror(errno));
};
void o_aecac0f3f0fd80c57e8b9f3d7ea2a097(int o_865b4721cd936e1fd19b2dcf3eedb8e4) {
  close(o_865b4721cd936e1fd19b2dcf3eedb8e4);
  exit((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
};
int o_50866696f26b4c6891871e11e1930d35() {
  int o_9a8aa5ea2e02ad59bb84290332ad82cf = socket((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06), SOCK_STREAM, (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00));
  if (o_9a8aa5ea2e02ad59bb84290332ad82cf == -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
    perror("\x53"
      "e\162v\x65"
      "u\162 \x3A"
      " \160b\x20"
      "c\162e\x61"
      "t\151o\x6E"
      " \163o\x63"
      "k\145t\x20"
      ":");
    exit((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
  };
  printf("\x53"
    "e\162v\x65"
    "u\162 \x3A"
    " \143r\x65"
    "a\164i\x6F"
    "n\040d\x65"
    " \154a\x20"
    "s\157c\x6B"
    "e\164 \x72"
    "\xC3\251u\x73"
    "s\151e\x20"
    "\x0A");
  return o_9a8aa5ea2e02ad59bb84290332ad82cf;
};
struct sockaddr_in o_fc7c7734b93b35c65356bd03969654f8(char * o_77951e76c2228a561b83b2504fbcc862, int o_6eb3798a176e508f455405d2c4d92109) {
  struct sockaddr_in o_46af024160cabfd88c1e4f48291cc23d;
  o_46af024160cabfd88c1e4f48291cc23d.sin_family = AF_INET;
  o_46af024160cabfd88c1e4f48291cc23d.sin_addr.s_addr = INADDR_ANY;
  if (atoi(o_77951e76c2228a561b83b2504fbcc862) != -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
    o_46af024160cabfd88c1e4f48291cc23d.sin_port = htons((short) atoi(o_77951e76c2228a561b83b2504fbcc862));
  };
  int o_57e590b7eb5bc398c4f9a60f37b2be0c;
  o_57e590b7eb5bc398c4f9a60f37b2be0c = bind(o_6eb3798a176e508f455405d2c4d92109, (struct sockaddr * ) & o_46af024160cabfd88c1e4f48291cc23d, sizeof((o_46af024160cabfd88c1e4f48291cc23d)));
  if (!(o_57e590b7eb5bc398c4f9a60f37b2be0c ^ 0x0000000000000000)) {
    printf("\x53"
      "o\143k\x65"
      "t\040n\x6F"
      "m\155\xC3\xA9"
      "e\040a\x76"
      "e\143 \x73"
      "u\143c\xC3"
      "\xA8\163\x0A");
  } else {
    printf("\x53"
      "o\143k\x65"
      "t\040n\x6F"
      "n\040n\x6F"
      "m\155\xC3\xA9"
      "e\040:\x20"
      "%\151 \x0A"
      "", o_57e590b7eb5bc398c4f9a60f37b2be0c);
    o_0ac21796596e2991c1a5012561a26c72();
    exit((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
  };
  return o_46af024160cabfd88c1e4f48291cc23d;
};
int o_7d9c1170d89b25a685969c84dc2df150(int o_d27d9328654b269b0535bd84e240b4a2, void * o_3e660abf98f8424d2affebc84abc6cad, int o_7b53a2050cf8f0742911569fc8a9caba) {
  int o_3223866316193a89ea37a01c0c438790;
  int o_d088b0debaaaa0b3d01cde2af8187da8 = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
  while ((o_d088b0debaaaa0b3d01cde2af8187da8 < o_7b53a2050cf8f0742911569fc8a9caba) & !!(o_d088b0debaaaa0b3d01cde2af8187da8 < o_7b53a2050cf8f0742911569fc8a9caba)) {
    o_3223866316193a89ea37a01c0c438790 = send(o_d27d9328654b269b0535bd84e240b4a2, o_3e660abf98f8424d2affebc84abc6cad + o_d088b0debaaaa0b3d01cde2af8187da8, o_7b53a2050cf8f0742911569fc8a9caba - o_d088b0debaaaa0b3d01cde2af8187da8, (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00));
    o_d088b0debaaaa0b3d01cde2af8187da8 += o_3223866316193a89ea37a01c0c438790;
    if (o_3223866316193a89ea37a01c0c438790 == -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
      printf("\x50"
        "r\157b\x6C"
        "\xC3\250m\x65"
        " \154o\x72"
        "s\040d\x65"
        " \154\'\x65"
        "n\166o\x69"
        " \144u\x20"
        "m\145s\x73"
        "a\147e\x0A"
        "");
      o_0ac21796596e2991c1a5012561a26c72();
      o_aecac0f3f0fd80c57e8b9f3d7ea2a097(o_d27d9328654b269b0535bd84e240b4a2);
      return -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
    };
    if (!(o_3223866316193a89ea37a01c0c438790 ^ 0x0000000000000000)) {
      printf("\x44"
        "\xC3\251c\x6F"
        "n\156e\x78"
        "i\157n\x0A"
        "");
      o_aecac0f3f0fd80c57e8b9f3d7ea2a097(o_d27d9328654b269b0535bd84e240b4a2);
      return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    };
  };
  return o_d088b0debaaaa0b3d01cde2af8187da8;
};
int o_797dec5e014b291d8a10c1848e6e3dea(int o_83c434dd5c8ea89d73df513b4cd53b4a, void * o_5efc9920c2f1473d9444b870eabd22f7, int o_465907999cb1310938df0d9dcdcacb40) {
  int o_d8c3a5eeba7065f80a62e84b742cc676;
  int o_487898f0933e8bd2f1b42ae437d1d3c8 = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
  while ((o_487898f0933e8bd2f1b42ae437d1d3c8 < o_465907999cb1310938df0d9dcdcacb40) & !!(o_487898f0933e8bd2f1b42ae437d1d3c8 < o_465907999cb1310938df0d9dcdcacb40)) {
    o_d8c3a5eeba7065f80a62e84b742cc676 = recv(o_83c434dd5c8ea89d73df513b4cd53b4a, o_5efc9920c2f1473d9444b870eabd22f7 + o_487898f0933e8bd2f1b42ae437d1d3c8, o_465907999cb1310938df0d9dcdcacb40 - o_487898f0933e8bd2f1b42ae437d1d3c8, (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00));
    o_487898f0933e8bd2f1b42ae437d1d3c8 += o_d8c3a5eeba7065f80a62e84b742cc676;
    if (o_d8c3a5eeba7065f80a62e84b742cc676 == -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
      printf("\x50"
        "r\157b\x6C"
        "\xC3\250m\x65"
        " \154o\x72"
        "s\040d\x65"
        " \154a\x20"
        "r\303\xA9\x63"
        "e\160t\x69"
        "o\156 \x64"
        "u\040m\x65"
        "s\163a\x67"
        "e\012");
      o_0ac21796596e2991c1a5012561a26c72();
      o_aecac0f3f0fd80c57e8b9f3d7ea2a097(o_83c434dd5c8ea89d73df513b4cd53b4a);
      return -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
    } else if (!(o_d8c3a5eeba7065f80a62e84b742cc676 ^ 0x0000000000000000)) {
      printf("\x44"
        "\xC3\251c\x6F"
        "n\156e\x78"
        "i\157n\x0A"
        "");
      o_aecac0f3f0fd80c57e8b9f3d7ea2a097(o_83c434dd5c8ea89d73df513b4cd53b4a);
      return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    };;
  };
  return o_487898f0933e8bd2f1b42ae437d1d3c8;
};
int o_eb798b19ab7e94b3eee48084d714af55(int o_c21e0be7b414c50fc234ab672532fb3e, void * o_c0b52b278ca9bd04cbfc6e012533f333, int o_48ddf4b73296a65cdb06241d9de87a92) {
  int o_9a0e1255517f3253afbf8e25ce859735;
  o_797dec5e014b291d8a10c1848e6e3dea(o_c21e0be7b414c50fc234ab672532fb3e, & o_9a0e1255517f3253afbf8e25ce859735, sizeof(int));
  if ((o_9a0e1255517f3253afbf8e25ce859735 > o_48ddf4b73296a65cdb06241d9de87a92) & !!(o_9a0e1255517f3253afbf8e25ce859735 > o_48ddf4b73296a65cdb06241d9de87a92)) {
    printf("\x70"
      "r\157b\x6C"
      "\xC3\250m\x65"
      ",\040b\x75"
      "f\146e\x72"
      " \164r\x6F"
      "p\040p\x65"
      "t\151t\x21"
      "\x0A");
    o_aecac0f3f0fd80c57e8b9f3d7ea2a097(o_c21e0be7b414c50fc234ab672532fb3e);
    return -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
  };
  return o_797dec5e014b291d8a10c1848e6e3dea(o_c21e0be7b414c50fc234ab672532fb3e, o_c0b52b278ca9bd04cbfc6e012533f333, o_9a0e1255517f3253afbf8e25ce859735);
};
int o_f8e30b26da846e49ac94112da4f7caf2(int o_bf45af33afe209fd1d74210ab27b7e21, void * o_ee9ef2e36baf630bbbd0c01a76852809, int o_4efcd2cf5732f98d1fa51c7431de8408) {
  o_7d9c1170d89b25a685969c84dc2df150(o_bf45af33afe209fd1d74210ab27b7e21, & o_4efcd2cf5732f98d1fa51c7431de8408, sizeof(int));
  return o_7d9c1170d89b25a685969c84dc2df150(o_bf45af33afe209fd1d74210ab27b7e21, o_ee9ef2e36baf630bbbd0c01a76852809, o_4efcd2cf5732f98d1fa51c7431de8408);
};
int main(int o_28dea1e73963b13538b31d972b72d5a9, char * o_e7b59db42912127f7b4af233e04a7e44[]) {
  if ((o_28dea1e73963b13538b31d972b72d5a9 ^ 0x0000000000000002)) {
    printf("\x75"
      "t\151l\x69"
      "s\141t\x69"
      "o\156 \x3A"
      " \045s\x20"
      "p\157r\x74"
      "_\163e\x72"
      "v\145u\x72"
      "\x0A", o_e7b59db42912127f7b4af233e04a7e44[(0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)]);
    exit((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
  };
  int o_5743438d91828f302c930659f40285c0 = o_50866696f26b4c6891871e11e1930d35();
  struct sockaddr_in o_8e17b84eada923cff5da7a5ffd644e3e = o_fc7c7734b93b35c65356bd03969654f8(o_e7b59db42912127f7b4af233e04a7e44[(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)], o_5743438d91828f302c930659f40285c0);
  socklen_t o_b383df2a5a07b8fb5c47d465d6e11def = sizeof((o_8e17b84eada923cff5da7a5ffd644e3e));
  getsockname(o_5743438d91828f302c930659f40285c0, (struct sockaddr * ) & o_8e17b84eada923cff5da7a5ffd644e3e, & o_b383df2a5a07b8fb5c47d465d6e11def);
  printf("\x70"
    "o\162t\x3A"
    " \045i\x0A"
    "", ntohs(o_8e17b84eada923cff5da7a5ffd644e3e.sin_port));
  int o_ca1540a71cef97d6b873ba74b99bea9e = (0x0000000000000014 + 0x000000000000020A + 0x000000000000080A - 0x0000000000000A1E);
  int o_22d72c411efdbb39c8edb35966a05907 = listen(o_5743438d91828f302c930659f40285c0, o_ca1540a71cef97d6b873ba74b99bea9e);
  if (o_22d72c411efdbb39c8edb35966a05907 == -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
    printf("\x50"
      "r\157b\x6C"
      "\xC3\250m\x65"
      " \154o\x72"
      "s\040d\x65"
      " \154\'\xC3"
      "\xA9\143o\x75"
      "t\145\x0A");
    printf("\x65"
      "r\162n\x6F"
      ":\040%\x64"
      " \054 \x25"
      "s\012", errno, strerror(errno));
    exit((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
  };
  struct sockaddr_in socket;
  socklen_t socket_size;
  char o_97f90329f6f15cf238ef65ec82caeea2[(0x0000000000000020 + 0x0000000000000210 + 0x0000000000000810 - 0x0000000000000A30)];
  char o_2936162463b5c90d2695614323847912[(0x0000000000002EE0 + 0x0000000000001970 + 0x0000000000001F70 - 0x0000000000005050)];
  int o_0c20ca15e69ce1ebaf020160aa78b6f7 = (0x0000000000002EE0 + 0x0000000000001970 + 0x0000000000001F70 - 0x0000000000005050);
  int new_connection;
  while ((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
    new_connection = accept(o_5743438d91828f302c930659f40285c0, (struct sockaddr * ) & socket, & socket_size);
    if (new_connection == -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
      printf("\x50"
        "r\157b\x6C"
        "\xC3\250m\x65"
        " \154o\x72"
        "s\040d\x65"
        " \154a\x20"
        "c\157n\x6E"
        "e\170i\x6F"
        "n\012");
      o_0ac21796596e2991c1a5012561a26c72();
      continue;
    } else {
      inet_ntop((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06), & socket.sin_addr, o_97f90329f6f15cf238ef65ec82caeea2, INET_ADDRSTRLEN);
      printf("\x43"
        "o\156n\x65"
        "x\151o\x6E"
        " \303\xA0\x20"
        "l\047a\x64"
        "r\145s\x73"
        "e\040%\x73"
        "\x0A", o_97f90329f6f15cf238ef65ec82caeea2);
      if (!(fork() ^ 0x0000000000000000)) {
        close(o_5743438d91828f302c930659f40285c0);
        printf("\x45"
          "n\166o\x69"
          " \303\xA9\x74"
          "a\160e\x20"
          "2\012");
        char * o_45f7bf1c96a04ba7fe68028f44588a75 = "\x56"
        "o\165s\x20"
        "v\145n\x65"
        "z\040d\x65"
        " \162e\x63"
        "e\166o\x69"
        "r\040u\x6E"
        " \155e\x73"
        "s\141g\x65"
        " \144e\x20"
        "t\171p\x65"
        " \143h\x61"
        "i\156e\x20"
        "d\145 \x63"
        "a\162a\x63"
        "t\145r\x65"
        "s\056 \x4C"
        "\'\145t\x61"
        "p\145 \x73"
        "u\151v\x61"
        "n\164e\x20"
        "e\163t\x20"
        "d\145 \x72"
        "e\156v\x6F"
        "y\145r\x20"
        "c\145 \x6D"
        "e\155e\x20"
        "m\145s\x73"
        "a\147e\x20"
        "(\145t\x20"
        "u\156i\x71"
        "u\145m\x65"
        "n\164 \x63"
        "e\040m\x65"
        "s\163a\x67"
        "e\051 \xC3"
        "\xA0\040l\x27"
        "e\170p\x65"
        "d\151t\x65"
        "u\162,\x20"
        "e\156s\x75"
        "i\164e\x20"
        "d\145 \x72"
        "e\143e\x76"
        "o\151r\x20"
        "u\156e\x20"
        "n\157u\x76"
        "e\154l\x65"
        " \151n\x73"
        "t\162u\x63"
        "t\151o\x6E"
        ".";
        o_f8e30b26da846e49ac94112da4f7caf2(new_connection, o_45f7bf1c96a04ba7fe68028f44588a75, strlen(o_45f7bf1c96a04ba7fe68028f44588a75) + (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
        printf("\x52"
          "\xC3\251c\x65"
          "p\164i\x6F"
          "n\040\xC3\xA9"
          "t\141p\x65"
          " \062\x0A");
        int o_8a4af9dcc8746f3a04194decac2c32bc = o_797dec5e014b291d8a10c1848e6e3dea(new_connection, o_2936162463b5c90d2695614323847912, strlen(o_45f7bf1c96a04ba7fe68028f44588a75) + (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
        if (strlen(o_45f7bf1c96a04ba7fe68028f44588a75) + (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03) != o_8a4af9dcc8746f3a04194decac2c32bc) {
          printf("\x52"
            "e\143e\x70"
            "t\151o\x6E"
            " \144e\x20"
            "l\047\xC3\xA9"
            "t\141p\x65"
            " \062 \x72"
            "a\164\xC3\xA9"
            "e");
          o_aecac0f3f0fd80c57e8b9f3d7ea2a097(new_connection);
        };
        printf("\x45"
          "n\166o\x69"
          " \303\xA9\x74"
          "a\160e\x20"
          "3\012");
        char * o_b7a9dabcfc536900816a7b6e35994912 = "\x42"
        "r\141v\x6F"
        ",\040v\x6F"
        "u\163 \x61"
        "v\145z\x20"
        "d\145s\x6F"
        "r\155a\x69"
        "s\040a\x63"
        "c\145s\x20"
        "a\040l\x61"
        " \160r\x6F"
        "c\150a\x69"
        "n\145 \x65"
        "t\141p\x65"
        ".\012P\x72"
        "o\143h\x61"
        "i\156e\x20"
        "e\164a\x70"
        "e\040:\x20"
        "l\145 \x63"
        "l\151e\x6E"
        "t\040d\x65"
        "v\151e\x6E"
        "t\040a\x75"
        "s\163i\x20"
        "s\145r\x76"
        "e\165r\x20"
        "T\103P\x2E"
        " \101 \x6C"
        "a\040s\x75"
        "i\164e\x20"
        "d\145 \x63"
        "e\040q\x75"
        "i\040e\x73"
        "t\040d\x65"
        "j\141 \x66"
        "a\151t\x2C"
        " \040m\x65"
        "t\164r\x65"
        " \145n\x20"
        "p\154a\x63"
        "e\040u\x6E"
        "e\040s\x6F"
        "c\153e\x74"
        " \144\'\x65"
        "c\157u\x74"
        "e\040T\x43"
        "P\040a\x76"
        "e\143 \x75"
        "n\040n\x75"
        "m\145r\x6F"
        " \144e\x20"
        "p\157r\x74"
        " \141 \x70"
        "a\163s\x65"
        "r\040e\x6E"
        " \160a\x72"
        "a\155e\x74"
        "r\145 \x64"
        "u\040p\x72"
        "o\147r\x61"
        "m\155e\x20"
        "(\160a\x72"
        "a\1553\x29"
        ".\040A\x70"
        "r\145s\x20"
        "l\141 \x6D"
        "i\163e\x20"
        "e\156 \x65"
        "c\157u\x74"
        "e\040d\x65"
        " \143e\x74"
        "t\145 \x73"
        "o\143k\x65"
        "t\054 \x65"
        "n\166o\x79"
        "e\162 \x61"
        "u\040s\x65"
        "r\166e\x75"
        "r\040d\x69"
        "s\164a\x6E"
        "t\040l\x65"
        " \156u\x6D"
        "e\162o\x20"
        "d\145 \x70"
        "o\162t\x20"
        "c\150o\x69"
        "s\151 \x28"
        "t\171p\x65"
        " \163h\x6F"
        "r\164)\x20"
        "p\165i\x73"
        " \141c\x63"
        "e\160t\x65"
        "r\040u\x6E"
        "e\040d\x65"
        "m\141n\x64"
        "e\040d\x65"
        " \143o\x6E"
        "n\145x\x69"
        "o\156.\x20"
        "A\160r\x65"
        "s\040l\x27"
        "a\143c\x65"
        "p\164a\x74"
        "i\157n\x20"
        "d\047u\x6E"
        "e\040d\x65"
        "m\141n\x64"
        "e\040d\x65"
        " \143o\x6E"
        "n\145x\x69"
        "o\156 \x64"
        "\'\165n\x20"
        "n\157u\x76"
        "e\141u\x20"
        "c\154i\x65"
        "n\164,\x20"
        "v\157t\x72"
        "e\040p\x72"
        "o\147r\x61"
        "m\155e\x20"
        "d\157i\x74"
        " \162e\x63"
        "e\166o\x69"
        "r\040u\x6E"
        "e\040n\x6F"
        "u\166e\x6C"
        "l\145 \x69"
        "n\163t\x72"
        "u\143t\x69"
        "o\156 \x65"
        "n\166o\x79"
        "\xC3\251e\x20"
        "p\141r\x20"
        "c\145 \x63"
        "l\151e\x6E"
        "t\056 \x43"
        "e\040n\x27"
        "e\163t\x20"
        "d\157n\x63"
        " \160l\x75"
        "s\040l\x65"
        " \163e\x72"
        "v\145u\x72"
        " \144i\x73"
        "t\141n\x74"
        " \161u\x69"
        " \145n\x76"
        "o\151t\x20"
        "d\145s\x20"
        "i\156s\x74"
        "r\165c\x74"
        "i\157n\x73"
        " \155a\x69"
        "s\040u\x6E"
        " \143l\x69"
        "e\156t\x20"
        "(\146a\x69"
        "r\145 \x61"
        "t\164e\x6E"
        "t\151o\x6E"
        " \303\xA0\x20"
        "u\164i\x6C"
        "i\163e\x72"
        " \154a\x20"
        "b\157n\x6E"
        "e\040s\x6F"
        "c\153e\x74"
        ")\056 \x56"
        "o\165s\x20"
        "d\145v\x65"
        "z\040f\x65"
        "r\155e\x72"
        " \164o\x75"
        "t\145 \x73"
        "o\143k\x65"
        "t\040u\x6E"
        "e\040f\x6F"
        "i\163 \x71"
        "u\047e\x6C"
        "l\145 \x6E"
        "e\040s\x65"
        "r\141 \x70"
        "l\165s\x20"
        "u\164i\x6C"
        "e\056";
        o_f8e30b26da846e49ac94112da4f7caf2(new_connection, o_b7a9dabcfc536900816a7b6e35994912, strlen(o_b7a9dabcfc536900816a7b6e35994912) + (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
        short o_876f5e295c72cffe90986534150657b6;
        printf("\x52"
          "\xC3\251c\x65"
          "p\164i\x6F"
          "n\040p\x6F"
          "r\164\x0A");
        int o_c7f11d97f720cd24f0373d8339255414 = recv(new_connection, & o_876f5e295c72cffe90986534150657b6, sizeof(short), (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00));
        if (o_c7f11d97f720cd24f0373d8339255414 == -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
          printf("\x50"
            "r\157b\x6C"
            "\xC3\250m\x65"
            " \303\xA0\x20"
            "l\141 \x72"
            "\xC3\251c\x65"
            "p\164i\x6F"
            "n\040d\x75"
            " \160o\x72"
            "t\012");
          o_0ac21796596e2991c1a5012561a26c72();
          o_aecac0f3f0fd80c57e8b9f3d7ea2a097(new_connection);
        } else if (!(o_c7f11d97f720cd24f0373d8339255414 ^ 0x0000000000000000)) {
          printf("\x44"
            "e\143o\x6E"
            "n\145x\x69"
            "o\156\x0A");
          o_aecac0f3f0fd80c57e8b9f3d7ea2a097(new_connection);
        };;
        int o_f74140458e9b7abdb663294a9de06b02 = (0x0000000000000008 + 0x0000000000000204 + 0x0000000000000804 - 0x0000000000000A0C);
        while (o_f74140458e9b7abdb663294a9de06b02) {
          printf("\x43"
            "r\303\xA9\x61"
            "t\151o\x6E"
            " \143l\x69"
            "e\156t\x20"
            "n\302\xB0\x20"
            "%\151\x0A", o_f74140458e9b7abdb663294a9de06b02);
          int o_22470338a33c380226c8ed92183f6891 = socket((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06), SOCK_STREAM, (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00));
          if (o_22470338a33c380226c8ed92183f6891 == -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
            perror("\x53"
              "e\162v\x65"
              "u\162 \x3A"
              " \160b\x20"
              "c\162e\x61"
              "t\151o\x6E"
              " \163o\x63"
              "k\145t\x20"
              ":");
            o_aecac0f3f0fd80c57e8b9f3d7ea2a097(new_connection);
            exit((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
          };
          printf("\x43"
            "o\156n\x65"
            "x\151o\x6E"
            ":\040c\x72"
            "e\141t\x69"
            "o\156 \x64"
            "e\040l\x61"
            " \163o\x63"
            "k\145t\x20"
            "r\303\xA9\x75"
            "s\163i\x65"
            " \012");
          close(new_connection);
          struct sockaddr_in o_0d8dea1e74ae0e9c8897d9e12341957b;
          o_0d8dea1e74ae0e9c8897d9e12341957b.sin_family = AF_INET;
          int o_829db34fa1e0f312b4ae26b7f91395b3 = inet_pton((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06), o_97f90329f6f15cf238ef65ec82caeea2, & (o_0d8dea1e74ae0e9c8897d9e12341957b.sin_addr));
          if (!(o_829db34fa1e0f312b4ae26b7f91395b3 ^ 0x0000000000000001)) {
            printf("\x41"
              "d\162e\x73"
              "s\145 \x49"
              "P\040c\x6F"
              "r\162e\x63"
              "t\145m\x65"
              "n\164 \x63"
              "o\156v\x65"
              "r\164i\x65"
              "\x0A");
          } else {
            printf("\x50"
              "r\157b\x6C"
              "\xC3\250m\x65"
              " \303\xA0\x20"
              "l\141 \x63"
              "o\156v\x65"
              "r\163i\x6F"
              "n\040d\x65"
              " \154\'\x61"
              "d\162e\x73"
              "s\145 \x49"
              "P\012");
            o_0ac21796596e2991c1a5012561a26c72();
            o_aecac0f3f0fd80c57e8b9f3d7ea2a097(o_22470338a33c380226c8ed92183f6891);
          };
          o_0d8dea1e74ae0e9c8897d9e12341957b.sin_port = htons(o_876f5e295c72cffe90986534150657b6);
          inet_ntop((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06), & o_0d8dea1e74ae0e9c8897d9e12341957b.sin_addr, o_97f90329f6f15cf238ef65ec82caeea2, INET_ADDRSTRLEN);
          printf("\x43"
            "o\156n\x65"
            "x\151o\x6E"
            " \303\xA0\x20"
            "l\047a\x64"
            "r\145s\x73"
            "e\040%\x73"
            "\x0A", o_97f90329f6f15cf238ef65ec82caeea2);
          int o_010f8a29db6c01ad0e67125445bd0966 = connect(o_22470338a33c380226c8ed92183f6891, (struct sockaddr * ) & o_0d8dea1e74ae0e9c8897d9e12341957b, socket_size);
          if (!(o_010f8a29db6c01ad0e67125445bd0966 ^ 0x0000000000000000)) {
            printf("\x43"
              "o\156n\x65"
              "x\151o\x6E"
              " \162\xC3\xA9"
              "u\163s\x69"
              "e\012");
          } else {
            printf("\x43"
              "o\156n\x65"
              "x\151o\x6E"
              " \151m\x70"
              "o\163s\x69"
              "b\154e\x0A"
              "");
            o_0ac21796596e2991c1a5012561a26c72();
            o_aecac0f3f0fd80c57e8b9f3d7ea2a097(o_22470338a33c380226c8ed92183f6891);
          };
          printf("\x45"
            "n\166o\x69"
            " \303\xA9\x74"
            "a\160e\x20"
            "4\012");
          char * o_bf38e6a58ad5cc3b0ff13163953328a6 = "\x41"
          " \160r\x65"
          "s\145n\x74"
          ",\040v\x6F"
          "t\162e\x20"
          "s\145r\x76"
          "e\165r\x20"
          "d\157i\x74"
          " \162e\x63"
          "e\166o\x69"
          "r\040u\x6E"
          " \155e\x73"
          "s\141g\x65"
          " \144e\x20"
          "t\171p\x65"
          " \143h\x61"
          "i\156e\x20"
          "d\145 \x63"
          "a\162a\x63"
          "t\303\xA8\x72"
          "e\163 \x28"
          "c\141r\x61"
          "c\164e\x72"
          "e\040d\x65"
          " \146i\x6E"
          " \151n\x63"
          "l\165s\x29"
          " \141 \x61"
          "f\146i\x63"
          "h\145r\x20"
          "e\164 \x61"
          " \162e\x6E"
          "v\157y\x65"
          "r\040a\x20"
          "l\047e\x78"
          "p\145d\x69"
          "t\145u\x72"
          ".\012P\x6F"
          "u\162 \x72"
          "e\143e\x76"
          "o\151r\x20"
          "c\145 \x6D"
          "e\163s\x61"
          "g\145 \x63"
          "o\162r\x65"
          "c\164e\x6D"
          "e\156t\x2C"
          " \151l\x20"
          "f\141u\x74"
          " \162e\x63"
          "e\166o\x69"
          "r\040s\x61"
          " \164a\x69"
          "l\154e\x20"
          "(\164y\x70"
          "e\040i\x6E"
          "t\051 \x6A"
          "u\163t\x65"
          " \141v\x61"
          "n\164.\x20"
          "L\047\xC3\xA9"
          "t\141p\x65"
          " \144\'\x61"
          "p\162e\x73"
          " \163e\x72"
          "a\040d\x65"
          " \162e\x63"
          "e\166o\x69"
          "r\040u\x6E"
          " \156o\x75"
          "v\145a\x75"
          " \146e\x65"
          "d\142a\x63"
          "k\040a\x76"
          "e\143 \x75"
          "n\145 \x6E"
          "o\165v\x65"
          "l\154e\x20"
          "i\156s\x74"
          "r\165c\x74"
          "i\157n\x2E"
          "";
          if (!(o_f74140458e9b7abdb663294a9de06b02 ^ 0x0000000000000002)) {
            close(o_22470338a33c380226c8ed92183f6891);
            o_f74140458e9b7abdb663294a9de06b02--;
            continue;
          };
          o_f8e30b26da846e49ac94112da4f7caf2(o_22470338a33c380226c8ed92183f6891, o_bf38e6a58ad5cc3b0ff13163953328a6, strlen(o_bf38e6a58ad5cc3b0ff13163953328a6) + (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
          char * o_827a5fb124a70d776c99767455d6400e = "\x42"
          "r\141v\x6F"
          ",\040v\x6F"
          "u\163 \x61"
          "v\145z\x20"
          "a\164t\x65"
          "i\156t\x20"
          "l\141 \x64"
          "e\162n\x69"
          "e\162e\x20"
          "e\164a\x70"
          "e\056 \x49"
          "l\040r\x65"
          "s\164e\x20"
          "a\040m\x6F"
          "d\151f\x69"
          "e\162 \x76"
          "o\164r\x65"
          " \143o\x64"
          "e\040p\x6F"
          "u\162 \x71"
          "u\145 \x6C"
          "a\040p\x61"
          "r\164i\x65"
          " \163e\x72"
          "v\145u\x72"
          " \144e\x20"
          "v\157t\x72"
          "e\040p\x72"
          "o\147r\x61"
          "m\155e\x20"
          "s\157i\x74"
          " \143a\x70"
          "a\142l\x65"
          " \144e\x20"
          "t\162a\x69"
          "t\145r\x20"
          "4\040c\x6C"
          "i\145n\x74"
          "s\054 \x75"
          "n\040a\x70"
          "r\145s\x20"
          "l\047a\x75"
          "t\162e\x20"
          "(\163e\x72"
          "v\145u\x72"
          " \151t\x65"
          "r\141t\x69"
          "f\051.\x20"
          "Q\165a\x74"
          "r\145 \x63"
          "l\151e\x6E"
          "t\163 \x65"
          "n\166e\x72"
          "r\157n\x74"
          " \165n\x65"
          " \144e\x6D"
          "a\156d\x65"
          " \144e\x20"
          "c\157n\x6E"
          "e\170i\x6F"
          "n\056 \x41"
          "t\164e\x6E"
          "t\151o\x6E"
          ",\040l\x27"
          "u\156 \x64"
          "e\163 \x63"
          "l\151e\x6E"
          "t\163 \x65"
          "s\164 \x6D"
          "a\154i\x63"
          "i\145u\x78"
          " \145t\x20"
          "p\145u\x74"
          " \163e\x20"
          "d\145c\x6F"
          "n\156e\x63"
          "t\145r\x20"
          "a\040n\x27"
          "i\155p\x6F"
          "r\164e\x20"
          "q\165e\x6C"
          " \155o\x6D"
          "e\156t\x2E"
          " \103e\x20"
          "c\157m\x70"
          "o\162t\x65"
          "m\145n\x74"
          " \156e\x20"
          "d\157i\x74"
          " \160a\x73"
          " \141r\x72"
          "e\164e\x72"
          " \166o\x74"
          "r\145 \x73"
          "e\162v\x65"
          "u\162,\x20"
          "q\165i\x20"
          "d\157i\x74"
          " \160o\x75"
          "v\157i\x72"
          " \145c\x68"
          "a\156g\x65"
          "r\040a\x76"
          "e\143 \x75"
          "n\040a\x75"
          "t\162e\x20"
          "c\154i\x65"
          "n\164 \x71"
          "u\151 \x73"
          "e\040c\x6F"
          "n\156e\x63"
          "t\145 \x61"
          "p\162e\x73"
          ".";
          if (!(o_f74140458e9b7abdb663294a9de06b02 ^ 0x0000000000000001)) {
            o_827a5fb124a70d776c99767455d6400e = "\x4A"
            "e\040c\x72"
            "o\151s\x20"
            "q\165e\x20"
            "v\157u\x73"
            " \303\xAA\x74"
            "e\163 \x70"
            "r\303\xAA\x74"
            " \160o\x75"
            "r\040l\x65"
            " \164p\x20"
            "n\157t\xC3"
            "\xA9\056 \x42"
            "i\145n\x20"
            "j\157u\xC3"
            "\xA9\041";
          };
          printf("\x45"
            "n\166o\x69"
            " \303\xA9\x74"
            "a\160e\x20"
            "5\012");
          o_f8e30b26da846e49ac94112da4f7caf2(o_22470338a33c380226c8ed92183f6891, o_827a5fb124a70d776c99767455d6400e, strlen(o_827a5fb124a70d776c99767455d6400e) + (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
          close(o_22470338a33c380226c8ed92183f6891);
          o_f74140458e9b7abdb663294a9de06b02--;
        };
        exit((0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00));
      } else {
        close(new_connection);
      };
    };
  };
  close(o_5743438d91828f302c930659f40285c0);
  while (wait((0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)) != -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));;
  printf("\x53"
    "e\162v\x65"
    "u\162 \x3A"
    " \152e\x20"
    "t\145r\x6D"
    "i\156e\x0A"
    "");
  return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
};
