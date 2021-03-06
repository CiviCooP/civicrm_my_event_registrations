<?php

civicrm_initialize();

$statusses = array();
$civi_status = civicrm_api3('ParticipantStatusType', 'get', array('options' => array('limit' => 999)));
foreach($civi_status['values'] as $civi_status) {
    switch ($civi_status['class']) {
        case 'Positive':
        case 'Pending':
            $statusses[$civi_status['id']] = $civi_status['id'];
            break;
    }
}

$cancel_id = civicrm_api3('ParticipantStatusType', 'getvalue', array('name' => 'Cancelled', 'return' => 'id'));

$view = new view();
$view->name = 'my_canceled_event_registrations';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_participant';
$view->human_name = 'My Canceled Event Registrations';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My past or canceled event registrations';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
    2 => '2',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'start_date' => 'start_date',
    'title' => 'title',
    'role' => 'role',
    'status' => 'status',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
    'id' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'start_date' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'title' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'role' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'status' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
);
/* No results behavior: Global: Unfiltered text */
$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
$handler->display->display_options['empty']['area_text_custom']['content'] = 'You do not have any canceled or past events';
/* Relationship: CiviCRM Participants: Event ID */
$handler->display->display_options['relationships']['event_id']['id'] = 'event_id';
$handler->display->display_options['relationships']['event_id']['table'] = 'civicrm_participant';
$handler->display->display_options['relationships']['event_id']['field'] = 'event_id';
$handler->display->display_options['relationships']['event_id']['label'] = 'Event';
$handler->display->display_options['relationships']['event_id']['required'] = TRUE;
/* Relationship: CiviCRM Participants: Participant's Contact ID */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_participant';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['label'] = 'Contact';
$handler->display->display_options['relationships']['contact_id']['required'] = TRUE;
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['relationship'] = 'contact_id';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Field: CiviCRM Participants: Participant ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_participant';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Events: Start Date */
$handler->display->display_options['fields']['start_date']['id'] = 'start_date';
$handler->display->display_options['fields']['start_date']['table'] = 'civicrm_event';
$handler->display->display_options['fields']['start_date']['field'] = 'start_date';
$handler->display->display_options['fields']['start_date']['relationship'] = 'event_id';
$handler->display->display_options['fields']['start_date']['label'] = 'Date';
$handler->display->display_options['fields']['start_date']['date_format'] = 'short';
/* Field: CiviCRM Events: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'civicrm_event';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'event_id';
$handler->display->display_options['fields']['title']['label'] = 'Event';
/* Field: CiviCRM Participants: Participant Role */
$handler->display->display_options['fields']['role']['id'] = 'role';
$handler->display->display_options['fields']['role']['table'] = 'civicrm_participant';
$handler->display->display_options['fields']['role']['field'] = 'role';
$handler->display->display_options['fields']['role']['label'] = 'My role';
/* Field: CiviCRM Participants: Participant Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'civicrm_participant';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['label'] = 'Status';
/* Sort criterion: CiviCRM Events: Start Date */
$handler->display->display_options['sorts']['start_date']['id'] = 'start_date';
$handler->display->display_options['sorts']['start_date']['table'] = 'civicrm_event';
$handler->display->display_options['sorts']['start_date']['field'] = 'start_date';
$handler->display->display_options['sorts']['start_date']['relationship'] = 'event_id';
$handler->display->display_options['filter_groups']['operator'] = 'OR';
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['uid_current']['value'] = '1';
$handler->display->display_options['filters']['uid_current']['group'] = 1;
/* Filter criterion: CiviCRM Events: Start Date */
$handler->display->display_options['filters']['start_date']['id'] = 'start_date';
$handler->display->display_options['filters']['start_date']['table'] = 'civicrm_event';
$handler->display->display_options['filters']['start_date']['field'] = 'start_date';
$handler->display->display_options['filters']['start_date']['operator'] = '<=';
$handler->display->display_options['filters']['start_date']['value']['value'] = 'now';
$handler->display->display_options['filters']['start_date']['value']['type'] = 'offset';
$handler->display->display_options['filters']['start_date']['group'] = 1;
/* Filter criterion: CiviCRM Participants: Participant Status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'civicrm_participant';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = $statusses;
$handler->display->display_options['filters']['status']['group'] = 1;
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current_1']['id'] = 'uid_current_1';
$handler->display->display_options['filters']['uid_current_1']['table'] = 'users';
$handler->display->display_options['filters']['uid_current_1']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current_1']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['uid_current_1']['value'] = '1';
$handler->display->display_options['filters']['uid_current_1']['group'] = 2;
/* Filter criterion: CiviCRM Participants: Participant Status */
$handler->display->display_options['filters']['status_1']['id'] = 'status_1';
$handler->display->display_options['filters']['status_1']['table'] = 'civicrm_participant';
$handler->display->display_options['filters']['status_1']['field'] = 'status';
$handler->display->display_options['filters']['status_1']['value'] = array(
    $cancel_id => $cancel_id,
);
$handler->display->display_options['filters']['status_1']['group'] = 2;
/* Filter criterion: CiviCRM Events: Start Date */
$handler->display->display_options['filters']['start_date_1']['id'] = 'start_date_1';
$handler->display->display_options['filters']['start_date_1']['table'] = 'civicrm_event';
$handler->display->display_options['filters']['start_date_1']['field'] = 'start_date';
$handler->display->display_options['filters']['start_date_1']['relationship'] = 'event_id';
$handler->display->display_options['filters']['start_date_1']['operator'] = '>=';
$handler->display->display_options['filters']['start_date_1']['value']['value'] = 'now';
$handler->display->display_options['filters']['start_date_1']['group'] = 2;
/* Filter criterion: CiviCRM Events: Start Date */
$handler->display->display_options['filters']['start_date_2']['id'] = 'start_date_2';
$handler->display->display_options['filters']['start_date_2']['table'] = 'civicrm_event';
$handler->display->display_options['filters']['start_date_2']['field'] = 'start_date';
$handler->display->display_options['filters']['start_date_2']['relationship'] = 'event_id';
$handler->display->display_options['filters']['start_date_2']['operator'] = '>=';
$handler->display->display_options['filters']['start_date_2']['value']['value'] = '-1 year';
$handler->display->display_options['filters']['start_date_2']['value']['type'] = 'offset';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'my-past-event-registrations';
$handler->display->display_options['menu']['title'] = 'My Event Registrations';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['my_canceled_event_registrations'] = array(
    t('Master'),
    t('My Canceled Event Registrations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('You do not have any canceled or past events'),
    t('Event'),
    t('Contact'),
    t('Drupal User'),
    t('.'),
    t('Date'),
    t('My role'),
    t('Status'),
    t('Page'),
);
