<?php

/**
 * @file
 * Contains Drupal\wizzlern_agency_general\Controller\DefaultController.
 */

namespace Drupal\wizzlern_agency_general\Controller;

use Drupal\Core\Controller\ControllerBase;

/**
 * Class DefaultController.
 */
class DefaultController extends ControllerBase {

  /**
   * Controller callback: Dummy page.
   *
   * @return array
   *   Return an empty page.
   */
  public function dummyPage() {
    return [];
  }

}
