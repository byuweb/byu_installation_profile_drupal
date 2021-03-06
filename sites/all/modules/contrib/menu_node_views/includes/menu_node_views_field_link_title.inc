<?php


/**
 * Views handler for menu links.
 */

class menu_node_views_field_link_title extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  function construct() {
    parent::construct();
    if (!empty($this->options['link_to_item'])) {
      $this->additional_fields['link_path'] = array('table' => 'menu_links', 'field' => 'link_path');
    }
    $this->additional_fields['display_depth'] = array('table' => 'menu_links', 'field' => 'depth');
  }

  /**
   * {@inheritdoc}
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_item'] = array('default' => TRUE);
    $options['check_access'] = array('default' => FALSE);
    $options['display_depth'] = array('default' => '');
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_item'] = array(
      '#title' => t('Link this field to its menu item'),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_item']),
    );
    $form['check_access'] = array(
      '#type' => 'checkbox',
      '#title' => t('Evaluate router path for access'),
      '#default_value' => $this->options['check_access'],
      '#description' => t('Will check if the path exists and is accessible for the current user. Might be useful, might be slow.'),
    );
    $form['display_depth'] = array(
      '#title' => t('Mark item depth'),
      '#description' => t('Enter a text element to use as a display marker.'),
      '#type' => 'textfield',
      '#size' => 10,
      '#default_value' => $this->options['display_depth'],
    );
  }

  /**
   * {@inheritdoc}
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_item']) && $data !== NULL && $data !== '') {
      $this->options['alter']['make_link'] = TRUE;
      $path = $this->get_value($values, 'link_path');
      $this->options['alter']['path'] = $path;
      // Check router menu item access for the current user.
      if ($this->options['check_access'] && !($path == '<front>' || url_is_external($path))) {
        $menu_item = menu_get_item($path);
        if (!$menu_item || empty($menu_item['access'])) {
          return '';
        }
      }
    }
    return $data;
  }

  /**
   * {@inheritdoc}
   */
  function render($values) {
    if (!empty($this->options['display_depth'])) {
      $text = check_plain($this->options['display_depth']);
      $max = $this->get_value($values, 'display_depth');
      $indentation = str_repeat($text, $max) . ' ';
    }
    else {
      $indentation = '';
    }
    $value = $indentation . $this->get_value($values);
    return $this->render_link(html_entity_decode($this->sanitize_value($value)), $values);
  }

}
