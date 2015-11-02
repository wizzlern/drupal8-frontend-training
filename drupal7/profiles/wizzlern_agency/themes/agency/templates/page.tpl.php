<?php

/**
 * @file
 * Overrides page.tpl.php
 *
 * Changes:
 *  - Removed secondary menu.
 *  - Removed breadcrumb
 *  - Removed left and right sidebar
 */
?>

<div id="page-wrapper"><div id="page">

  <?php print render($page['primary_menu']); ?>

  <!-- Header -->
  <header>
    <div class="container">
      <div class="intro-text">
        <?php print render($title_prefix); ?>
        <div class="intro-lead-in"><?php print $title; ?></div>
        <?php print render($title_suffix); ?>
        <div class="intro-heading"><?php print $site_slogan; ?></div>
        <?php print $tell_more_link; ?>
      </div>
    </div>
  </header>

  <?php print $messages; ?>
  <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
  <?php print render($page['content']); ?>

  <?php print render($page['footer']); ?>

</div>
