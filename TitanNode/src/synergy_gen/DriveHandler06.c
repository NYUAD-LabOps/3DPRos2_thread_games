/* generated thread source file - do not edit */
#include "DriveHandler06.h"

TX_THREAD DriveHandler06;
void DriveHandler06_create(void);
static void DriveHandler06_func(ULONG thread_input);
static uint8_t DriveHandler06_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.DriveHandler06") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void DriveHandler06_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&DriveHandler06, (CHAR*) "DriveHandler06", DriveHandler06_func, (ULONG) NULL,
                            &DriveHandler06_stack, 1024, 3, 3, 1, TX_DONT_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&DriveHandler06, 0);
    }
}

static void DriveHandler06_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    DriveHandler06_entry ();
}
