MEMORY
{
  ram (rwx) : ORIGIN = 0x20000000, LENGTH = 48K - 40
<<<<<<<< Updated upstream:buildroot/share/PlatformIO/ldscripts/ZONESTAR_ZM3E_512K.ld
  rom (rx)  : ORIGIN = 0x08005000, LENGTH = 512K - 20K - 4K
========
  rom (rx)  : ORIGIN = 0x08005000, LENGTH = 256K - 20K - 4K
>>>>>>>> Stashed changes:buildroot/share/PlatformIO/ldscripts/ZONESTAR_ZM3E_256K.ld
}

/* Provide memory region aliases for common.inc */
REGION_ALIAS("REGION_TEXT", rom);
REGION_ALIAS("REGION_DATA", ram);
REGION_ALIAS("REGION_BSS", ram);
REGION_ALIAS("REGION_RODATA", rom);

/* Let common.inc handle the real work. */
INCLUDE common.inc
