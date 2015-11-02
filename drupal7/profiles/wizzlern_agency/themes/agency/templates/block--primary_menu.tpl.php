<?php

/**
 * @file
 * Overwrite block.tpl.php
 *
 * Changes:
 *  - Changes block wrappers to <nav>.
 *  - Add navbar-header.
 *  - Add block content wrapper .navbar-collapse.
 */
?>
<nav class="navbar navbar-default navbar-fixed-top">
  <div class="container">
    <!-- Brand and toggle get grouped for better mobile display -->
    <div class="navbar-header page-scroll">
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
      <?php print render($title_prefix); ?>
      <a class="navbar-brand page-scroll" href="#page-top">Start Bootstrap</a>
      <?php print render($title_suffix); ?>
    </div>

    <!-- Collect the nav links, forms, and other content for toggling -->
    <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
    <?php print $content ?>
    </div>
  </div>
</nav>