
#define DBG_MEM_BASE 0xc0000000
#define INITCALL_ADDR DBG_MEM_BASE
#define INITCALL_SIZE 64
#define LOG_ADDR (INITCALL_ADDR + INITCALL_SIZE)
#define LOG_SIZE (1 << 17)

#define dbg_addr(addr) __va((phys_addr_t)(addr))

//#define WRITE_ENABLED
#define READ_ENABLED

extern char *log_buf;
