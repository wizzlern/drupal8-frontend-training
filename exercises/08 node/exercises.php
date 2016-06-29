<?php

// Oefeningen voor node-layout met eigen markup en losse velden.
// Geschatte tijd: 45 min.

// ==== Oefening 1 ====
// Pas de layout van de Portfolio node aan.
// - Bekijk de broncode van de "Rounded icons" portfolio-pagina in
//   "00 source/index.html".
// - Maak een aangepaste node-template voor de portfolio-pagina. Gebruik daarin
//   de layout uit de broncode.
// - Voeg daaraan de individuele node-velden aan toe.
// - Controleer het resultaat.

// ==== (extra) Oefening 2 ====
// Open de portfolio-nodes in een pop-up vanaf de voorpagina.
// - Gebruik de ng_lightbox module om een node in een pop-up te openen.
// - Met ng_lightbox kunnen (op dit moment) alleen bepaalde links in een pop-up
//   worden geopend. De links in de Portfolio-view naar de node niet. Na
//   onderzoek blijken de onderstaande Anchor-link attributen nodig te zijn om
//   deze in een pop-up te openen. Voeg deze in de View aan de link toe.
//     class="use-ajax" data-dialog-type="drupal_modal" data-dialog-options="{'width':700}"

// TODO Portfolio View aanpassen zodat deze werkt zonder preprocess/template override.

// ==== (extra) Oefening 3 ====
// Verplaats de HTML van View naar een template.

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Modify the contact form to match our design.
 */
function wizzlern_agency_form_contact_message_feedback_form_alter(&$form, \Drupal\Core\Form\FormStateInterface $form_state) {
}

* Template suggestion:
  - Suggestion voor image_formatter per image_style.
- Puzzelstuk: wizzlern_agency_preprocess_image_formatter()
    Onderzoek: $variables['link_attributes'] = new Attribute();
  - HTML-structuur van image_formatter
* Node template override:
  - Losse velden in custom structuur
    Puzzelstuk: HTML-structuur van node in pop-up
* Onderzoek mogelijkheid van View + node view-mode + node template override
