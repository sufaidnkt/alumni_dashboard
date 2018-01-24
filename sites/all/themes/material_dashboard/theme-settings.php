<?php
/**
 * Implements hook_form_system_theme_settings_alter()
 */


function material_dashboard_form_system_theme_settings_alter(&$form, &$form_state) {
    //logo icon
    $logo_icon = theme_get_setting('logo_icon');
    if (file_uri_scheme($logo_icon) == 'public') {
        $logo_icon = file_uri_target($logo_icon);
    }

    // Main settings wrapper
    $form['options'] = array(
        '#type' => 'vertical_tabs',
        '#default_tab' => 'defaults',
        '#weight' => '-10',
        '#attached' => array(
            'css' => array(drupal_get_path('theme', 'eps_diamond') . '/css/theme-options.css'),
        ),
    );

    // ----------- GENERAL -----------
    $form['options']['general'] = array(
        '#type' => 'fieldset',
        '#title' => t('General'),
    );

    // Breadcrumbs
    $form['options']['general']['breadcrumbs'] = array(
        '#type' => 'checkbox',
        '#title' => t('Breadcrumbs'),
        '#default_value' => theme_get_setting('breadcrumbs'),
    );


    $form['options']['general']['wrapper_logo_icon'] = array(
        '#type'    => 'fieldset',
        '#title' => t('Logo Icon'),
    );

    $form['options']['general']['wrapper_logo_icon']['logo_icon_checkbox'] = array(
        '#type'     => 'checkbox',
        '#title'    => t('Use the default logo icon'),
        '#default_value' => theme_get_setting('logo_icon_checkbox'),

    );

    $form['options']['general']['wrapper_logo_icon']['lg_wrapper'] = array(
        '#type'     => 'container',
        '#states'   => array(
            'visible'   => array(
                ':input[name=logo_icon_checkbox]' => array('checked' => false)
            )
        )
    );

    $form['options']['general']['wrapper_logo_icon']['lg_wrapper']['logo_icon'] = array(
        '#type' => 'textfield',
        '#title'=> t('Path to custom logo icon'),
        '#default_value' => $logo_icon,
    );

    $form['options']['general']['wrapper_logo_icon']['lg_wrapper']['logo_icon_upload'] = array(
        '#type' => 'file',
        '#title' => t('Upload Logo Icon'),
        '#default_value' => $logo_icon,
        '#description' => t('Upload a new Logo icon'),
    );

    // Powered By
    $form['options']['general']['poweredby'] = array(
        '#type' => 'textfield',
        '#title' => t('Powered By'),
        '#default_value' => theme_get_setting('poweredby'),
    );

	// ----------- DESIGN -----------
    $form['options']['design'] = array(
        '#type' => 'fieldset',
        '#title' => t('Layout Design'),
    );
    $form['options']['design']['fixed_header'] = array(
        '#type'     => 'checkbox',
        '#title'    => t('Fixed header'),
        '#description'    => t('Set your header position type'),
        '#default_value' => theme_get_setting('fixed_header'),
    );

    $form['options']['design']['fixed_aside'] = array(
        '#type'     => 'checkbox',
        '#title'    => t('Fixed aside'),
        '#description'    => t('Set your aside (left nemu) position'),
        '#default_value' => theme_get_setting('fixed_aside'),
    );

    $form['options']['design']['folded_aside'] = array(
        '#type'     => 'checkbox',
        '#title'    => t('Folded aside'),
        '#description'    => t('Set your aside (left nemu) position'),
        '#default_value' => theme_get_setting('folded_aside'),
    );

    $form['options']['design']['dock_aside'] = array(
        '#type'     => 'checkbox',
        '#title'    => t('Dock aside'),
        '#description'    => t('Set your aside (left nemu) position'),
        '#default_value' => theme_get_setting('dock_aside'),
    );

    $form['options']['design']['boxed_layout'] = array(
        '#type'     => 'checkbox',
        '#title'    => t('Boxed layout'),
        '#description'    => t('Set your boxed layout position'),
        '#default_value' => theme_get_setting('boxed_layout'),
    );

    // Header Option
    $form['options']['design']['layout_color_block'] = array(
        '#type' => 'radios',
        '#title' => t('Select a your theme color'),
        '#default_value' => theme_get_setting('layout_color_block'),
        '#options' => array(
            1 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-black header"></b><b class="bg-white header"></b><b class="bg-black"></b></span>',
            2 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-dark header"></b><b class="bg-white header"></b><b class="bg-dark"></b></span>',
            3 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-white header"></b><b class="bg-white header"></b><b class="bg-black"></b></span>',
            4 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-primary header"></b><b class="bg-white header"></b><b class="bg-dark"></b></span>',
            5 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-info header"></b><b class="bg-white header"></b><b class="bg-black"></b></span>',
            6 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-success header"></b><b class="bg-white header"></b><b class="bg-dark"></b></span>',
            7 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-danger header"></b><b class="bg-white header"></b><b class="bg-dark"></b></span>',
            8 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-black header"></b><b class="bg-black header"></b><b class="bg-white"></b></span>',
            9 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-dark header"></b><b class="bg-dark header"></b><b class="bg-light"></b></span>',
            10 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-info dker header"></b><b class="bg-info dker header"></b><b class="bg-light dker"></b></span>',
            11 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-primary header"></b><b class="bg-primary header"></b><b class="bg-dark"></b></span>',
            12 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-info dker header"></b><b class="bg-info dk header"></b><b class="bg-black"></b></span>',
            13 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-success header"></b><b class="bg-success header"></b><b class="bg-dark"></b></span>',
            14 => '<span class="block bg-light clearfix pos-rlt"><b class="bg-danger dker header"></b><b class="bg-danger dker header"></b><b class="bg-dark"></b></span>',

        ),
    );

    $form['options']['design']['color_switcher'] = array(
        '#type'     => 'checkbox',
        '#title'    => t('Theme settings'),
        '#description'    => t('Theme color switcher settings enable or not'),
        '#default_value' => theme_get_setting('color_switcher'),
    );
    $form['options']['design']['aside_width'] = array(
        '#type'     => 'select',
        '#options' => array('aside-lg'=>'Large aside','aside-xlg'=>'Extra large aside'),
        '#title'    => t('Aside Width / Left Menu Width'),
        '#default_value' => theme_get_setting('aside_width'),
        '#empty_option' => t('Disabled'),
        '#empty_value' => NULL,
    );
    // ----------- BootstrapCDN -----------
    $form['options']['bootstrap'] = array(
        '#type' => 'fieldset',
        '#title' => t('Bootstrap'),
    );

    $form['options']['bootstrap']['bootstrap_cdn'] = array(
        '#type' => 'fieldset',
        '#title' => t('BootstrapCDN'),
        '#description' => t('Use !bootstrapcdn to serve the Bootstrap framework files. Enabling this setting will prevent this theme from attempting to load any Bootstrap framework files locally. !warning', array(
          '!bootstrapcdn' => l(t('BootstrapCDN'), 'http://bootstrapcdn.com', array(
            'external' => TRUE,
          )),
          '!warning' => '<div class="alert alert-info messages info"><strong>' . t('NOTE') . ':</strong> ' . t('While BootstrapCDN (content distribution network) is the preferred method for providing huge performance gains in load time, this method does depend on using this third party service. BootstrapCDN is under no obligation or commitment to provide guaranteed up-time or service quality for this theme. If you choose to disable this setting, you must provide your own Bootstrap source and/or optional CDN delivery implementation.') . '</div>',
        )),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );

    $form['options']['bootstrap']['bootstrap_cdn']['bootstrap_cdn'] = array(
        '#type' => 'select',
        '#title' => t('BootstrapCDN version'),
        '#options' => drupal_map_assoc(array(
          '3.0.0',
          '3.0.1',
          '3.0.2',
          '3.0.3',
          '3.1.0',
          '3.1.1',
          '3.2.0',
          '3.3.0',
          '3.3.1',
          '3.3.2',
          '3.3.4',
          '3.3.5',
          '3.3.6',
        )),
        '#default_value' => theme_get_setting('bootstrap_cdn'),
        '#empty_option' => t('Disabled'),
        '#empty_value' => NULL,
    );
    $bootswatch_themes = array();
    $request = drupal_http_request('http://api.bootswatch.com/3/');
    if ($request && $request->code === '200' && !empty($request->data)) {
        if (($api = drupal_json_decode($request->data)) && is_array($api) && !empty($api['themes'])) {
          foreach ($api['themes'] as $bootswatch_theme) {
            $bootswatch_themes[strtolower($bootswatch_theme['name'])] = $bootswatch_theme['name'];
          }
        }
    }
    $form['options']['bootstrap']['bootstrap_cdn']['bootstrap_bootswatch'] = array(
        '#type' => 'select',
        '#title' => t('Bootswatch theme'),
        '#description' => t('Use !bootstrapcdn to serve a Bootswatch Theme. Choose Bootswatch theme here.', array(
          '!bootstrapcdn' => l(t('BootstrapCDN'), 'http://bootstrapcdn.com', array(
            'external' => TRUE,
          )),
        )),
        '#default_value' => theme_get_setting('bootstrap_bootswatch'),
        '#options' => $bootswatch_themes,
        '#empty_option' => t('Disabled'),
        '#empty_value' => NULL,
        '#suffix' => '<div id="bootswatch-preview"></div>',
        '#states' => array(
          'invisible' => array(
            ':input[name="bootstrap_cdn"]' => array('value' => ''),
          ),
        ),
    );

    if (empty($bootswatch_themes)) {
        $form['advanced']['bootstrap_cdn']['bootstrap_bootswatch']['#prefix'] = '<div class="alert alert-danger messages error"><strong>' . t('ERROR') . ':</strong> ' . t('Unable to reach Bootswatch API. Please ensure the server your website is hosted on is able to initiate HTTP requests.') . '</div>';
    }

    $form['options']['bootstrap']['bootstrap_cdn']['bootstrap_custom_css_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Bootstrap css'),
        '#description' => t('Please enter bootstrap css file location'),
        '#default_value' => theme_get_setting('bootstrap_custom_css_url'),
        '#suffix' => '<div id="bootstrap-custom-css-url-preview"></div>',
        '#empty_value' => NULL,
        '#states' => array(
          'visible' => array(
            ':input[name="bootstrap_cdn"]' => array('value' => ''),
          ),
        ),
    );

    $form['options']['bootstrap']['bootstrap_cdn']['bootstrap_custom_js_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Bootstrap js'),
        '#description' => t('Please enter bootstrap js file location'),
        '#default_value' => theme_get_setting('bootstrap_custom_js_url'),
        '#suffix' => '<div id="bootstrap-custom-js-url-preview"></div>',
        '#empty_value' => NULL,
        '#states' => array(
          'visible' => array(
            ':input[name="bootstrap_cdn"]' => array('value' => ''),
          ),
        ),
    );

    $form['options']['bootstrap']['bootstrap_tooltip_enabled'] = array(
        '#type' => 'checkbox',
        '#title' => t('Enable tooltips'),
        '#description' => t('Elements that have the !code attribute set will automatically initialize the tooltip upon page load. !warning', array(
          '!code' => '<code>data-toggle="tooltip"</code>',
          '!warning' => '<strong class="error text-error">WARNING: This feature can sometimes impact performance. Disable if pages appear to "hang" after initial load.</strong>',
        )),
        '#default_value' => theme_get_setting('bootstrap_tooltip_enabled'),
    );

    // Suppress jQuery message.
    $form['options']['bootstrap']['bootstrap_toggle_jquery_error'] = array(
        '#type' => 'checkbox',
        '#title' => t('Suppress jQuery version error message'),
        '#default_value' => theme_get_setting('bootstrap_toggle_jquery_error'),
        '#description' => t('Enable this if the version of jQuery has been upgraded to 1.7+ using a method other than the !jquery_update module.', array(
            '!jquery_update' => l(t('jQuery Update'), 'https://drupal.org/project/jquery_update'),
        )),
    );

    //---------- TOP MEMU ---------------

     $form['options']['header_menu'] = array(
        '#type' => 'fieldset',
        '#title' => 'Header Menu',
    );

    $form['options']['header_menu']['quick_link'] = array(
        '#type' => 'fieldset',
        '#title' => t('Header Quick Link'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );

    $form['options']['header_menu']['quick_link'] ['quick_link_name'] = array(
        '#type' => 'textfield',
        '#title' => t('Menu Title'),
        '#default_value' => theme_get_setting('quick_link_name'),
        '#description' => t('Your menu title or name , Example : Quick Link'),
    );

    $form['options']['header_menu']['new_link'] = array(
        '#type' => 'fieldset',
        '#title' => t('Header New Link'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );

    $form['options']['header_menu']['new_link'] ['new_link_name'] = array(
        '#type' => 'textfield',
        '#title' => t('Menu Title'),
        '#default_value' => theme_get_setting('new_link_name'),
        '#description' => t('Your menu title or name , Example : New Link'),
    );

    $form['options']['header_menu']['new_link'] ['new_link_menu'] = array(
        '#type' => 'textfield',
        '#title' => t('Menu name'),
        '#default_value' => theme_get_setting('new_link_menu'),
        '#description' => t('Your menu machine name, Example : main-menu'),
    );

    $form['options']['header_menu']['collapse_menu'] = array(
        '#type' => 'checkbox',
        '#title' => t('Collapse Menu'),
        '#default_value' => theme_get_setting('collapse_menu'),
        '#description' => t('Collapse menu enable or not'),
    );


    //---------- BLOCK CLASS ---------------

    $form['options']['block_class'] = array(
        '#type' => 'fieldset',
        '#title' => 'Block',
    );

    $form['options']['block_class']['block_class'] = array(
        '#type' => 'textarea',
        '#title' => t('Block Class'),
        '#default_value' => theme_get_setting('block_class'),
        '#description' => t('Your block class name, Format : &lt; block id &gt; | &lt; class name &gt; , Example : block-1|col-md-12'),
    );

    //---------- TABLE CLASS ---------------

    $form['options']['table_class'] = array(
        '#type' => 'fieldset',
        '#title' => 'Table',
    );

    $form['options']['table_class']['table_striped'] = array(
        '#type' => 'checkbox',
        '#title' => t('Table striped'),
        '#default_value' => theme_get_setting('table_striped'),
        '#description' => t('Table striped enable or not'),
    );

    $form['options']['table_class']['table_bordered'] = array(
        '#type' => 'checkbox',
        '#title' => t('Table bordered'),
        '#default_value' => theme_get_setting('table_bordered'),
        '#description' => t('Table bordered enable or not'),
    );

    $form['options']['table_class']['table_condensed'] = array(
        '#type' => 'checkbox',
        '#title' => t('Table condensed'),
        '#default_value' => theme_get_setting('table_condensed'),
        '#description' => t('Table condensed enable or not'),
    );

    $form['options']['table_class']['table_hover'] = array(
        '#type' => 'checkbox',
        '#title' => t('Table hover'),
        '#default_value' => theme_get_setting('table_hover'),
        '#description' => t('Table hover enable or not'),
    );

    $form['#submit'][] = 'material_dashboard_settings_submit_logo_icon';
}

function material_dashboard_settings_submit_logo_icon($form, &$form_state) {
    // upload logo icon
    $previous = 'public://' . $form['options']['general']['wrapper_logo_icon']['lg_wrapper']['logo_icon_upload']['#default_value'];
    $file = file_save_upload('logo_icon_upload');
    if ($file) {
        $parts = pathinfo($file->filename);
        $destination = 'public://' . $parts['basename'];
        $file->status = FILE_STATUS_PERMANENT;
        if (file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
            $_POST['logo_icon'] = $form_state['values']['logo_icon'] = $destination;
            if ($destination != $previous) {
                return;
            }
        }
    } else {
        // Avoid error when the form is submitted without specifying a new image
        $_POST['logo_icon'] = $form_state['values']['logo_icon'] = $previous;
    }

    // Update theme colors
    if(!empty($form_state['values']['layout_color_block'])){
        $theme_color = get_theme_color($form_state['values']['layout_color_block']);
        if(!empty($theme_color)){
            $form_state['values']['navbar_header_color'] = $theme_color['navbar_header_color'];
            $form_state['values']['navbar_collapse_color'] = $theme_color['navbar_collapse_color'];
            $form_state['values']['aside_color'] = $theme_color['aside_color'];
        }
    }
}

function get_theme_color($theme_key = null){

    $theme_color = array();

    $theme_color[1]['navbar_header_color'] = 'bg-black';
    $theme_color[1]['navbar_collapse_color'] = 'bg-white-only';
    $theme_color[1]['aside_color'] = 'bg-black';

    $theme_color[2]['navbar_header_color'] = 'bg-dark';
    $theme_color[2]['navbar_collapse_color'] = 'bg-white-only';
    $theme_color[2]['aside_color'] = 'bg-dark';

    $theme_color[3]['navbar_header_color'] = 'bg-white-only';
    $theme_color[3]['navbar_collapse_color'] = 'bg-white-only';
    $theme_color[3]['aside_color'] = 'bg-black';

    $theme_color[4]['navbar_header_color'] = 'bg-primary';
    $theme_color[4]['navbar_collapse_color'] = 'bg-white-only';
    $theme_color[4]['aside_color'] = 'bg-dark';

    $theme_color[5]['navbar_header_color'] = 'bg-info';
    $theme_color[5]['navbar_collapse_color'] = 'bg-white-only';
    $theme_color[5]['aside_color'] = 'bg-black';

    $theme_color[6]['navbar_header_color'] = 'bg-success';
    $theme_color[6]['navbar_collapse_color'] = 'bg-white-only';
    $theme_color[6]['aside_color'] = 'bg-dark';

    $theme_color[7]['navbar_header_color'] = 'bg-danger';
    $theme_color[7]['navbar_collapse_color'] = 'bg-white-only';
    $theme_color[7]['aside_color'] = 'bg-dark';

    $theme_color[8]['navbar_header_color'] = 'bg-black';
    $theme_color[8]['navbar_collapse_color'] = 'bg-black';
    $theme_color[8]['aside_color'] = 'bg-white b-r';


    $theme_color[9]['navbar_header_color'] = 'bg-dark';
    $theme_color[9]['navbar_collapse_color'] = 'bg-dark';
    $theme_color[9]['aside_color'] = 'bg-light';

    $theme_color[10]['navbar_header_color'] = 'bg-info dker';
    $theme_color[10]['navbar_collapse_color'] = 'bg-info dker';
    $theme_color[10]['aside_color'] = 'bg-light dker b-r';

    $theme_color[11]['navbar_header_color'] = 'bg-primary';
    $theme_color[11]['navbar_collapse_color'] = 'bg-primary';
    $theme_color[11]['aside_color'] = 'bg-dark';

    $theme_color[12]['navbar_header_color'] = 'bg-info dker';
    $theme_color[12]['navbar_collapse_color'] = 'bg-info dk';
    $theme_color[12]['aside_color'] = 'bg-black';

    $theme_color[13]['navbar_header_color'] = 'bg-success';
    $theme_color[13]['navbar_collapse_color'] = 'bg-success';
    $theme_color[13]['aside_color'] = 'bg-dark';

    $theme_color[14]['navbar_header_color'] = 'bg-danger dker bg-gd';
    $theme_color[14]['navbar_collapse_color'] = 'bg-danger dker bg-gd';
    $theme_color[14]['aside_color'] = 'bg-dark';

    return !empty($theme_color[$theme_key]) ? $theme_color[$theme_key] : '';
}
