<?php

// Oefeningen voor het aanpassen van formulieren.
// Geschatte tijd: 30 min.

// ==== Oefening 1 ====
// Voeg een contactformulier aan de pagina toe.
// - Schakel de Contactmodule in en voeg een veld voor telefoonnummer aan het
//   Feedback-formulier toe.
// - Download en installeer de Contact Block-module. Plaats een blok met het
//   Feedback-formulier op de voorpagina.
// - Vergelijk de HTML van het contactformulier met de HTML van de het
//   origineel en pas waar nodig de HTML van de Block-template aan.

// ==== Oefening 2 ====
// Pas de HTML van het contactformulier aan voor een goede layout.
// - De velden voor naam, e-mail en telefoon staan links van het berichtveld.
//   Gebruik een implementatie van hook_form_FORM_ID_alter() om wrapper(s) toe
//   te voegen voor deze layout. Kopieer de onderstaande functie daarvoor naar
//   het wizzlern_agency.theme.
// - Tip: Gebruik '#prefix' en '#suffix' om de wrapper HTML aan de render array
//   te voegen.

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Modify the contact form to match our design.
 */
function wizzlern_agency_form_contact_message_feedback_form_alter(&$form, \Drupal\Core\Form\FormStateInterface $form_state) {
}

// ==== Oefening 3 ====
// Voeg classes toe voor de juiste opmaak.
// - Gebruik de Devel-module en de dpr()-functie om de inhoud van de variabele
//   $form te bekijken.
// - Voeg CSS-klassen toe aan de 'submit'-knop voor een goed layout en styling.

// ==== Oefening 4 (extra) ====
// Verberg de labels van alle formuliervelden.
// - Gebruik de form_alter-functie ook om de labels van alle velden te
//   verbergen. Met configuratie kunnen veldlabels niet verborgen worden.
// - Tip: Gebruik geen unset(), dan worden de labels uit de HTML-verwijderd.
//   Gebruik het attribuut '#title_display'.

// ==== Oefening 5 (extra) ====
// Voeg een placeholder aan de formuliervelden toe als vervanging van het label.
// - Gebruik de hook_preprocess_FORM_ELEMENT() om een attribuut ‘paceholder’ aan
//   de velden toe te voegen. Gebruik het oorspronkelijke label als de tekst van
//   de placeholder.
