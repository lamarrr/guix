/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** GUIX Component                                                        */
/**                                                                       */
/**   Widget Management (Widget)                                          */
/**                                                                       */
/**************************************************************************/

#define GX_SOURCE_CODE


/* Include necessary system files.  */

#include "gx_api.h"
#include "gx_widget.h"

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _gx_first_client_child_get                          PORTABLE C      */
/*                                                           6.0          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Kenneth Maxwell, Microsoft Corporation                              */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function get the first client child.                           */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    parent                                Pointer to parent widget      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    test                                  First client child            */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _gx_drop_list_event_process                                         */
/*    _gx_horizontal_list_event_process                                   */
/*    _gx_horizontal_list_left_wrap                                       */
/*    _gx_horizontal_list_right_wrap                                      */
/*    _gx_horizontal_list_scroll_info_get                                 */
/*    _gx_horizontal_list_slide_back_check                                */
/*    _gx_vertical_list_down_wrap                                         */
/*    _gx_vertical_list_event_process                                     */
/*    _gx_vertical_list_scroll_info_get                                   */
/*    _gx_vertical_list_slide_back_check                                  */
/*    _gx_vertical_list_up_wrap                                           */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020     Kenneth Maxwell          Initial Version 6.0           */
/*                                                                        */
/**************************************************************************/
GX_WIDGET *_gx_widget_first_client_child_get(GX_WIDGET *parent)
{
GX_WIDGET *test = parent -> gx_widget_first_child;

    while (test && (test -> gx_widget_status & GX_STATUS_NONCLIENT))
    {
        test = test -> gx_widget_next;
    }
    return test;
}

