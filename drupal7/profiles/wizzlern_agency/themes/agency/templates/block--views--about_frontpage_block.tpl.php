<?php

/**
 * @todo Document the changes.
 */
?>
<section id="about">
  <div class="container">

    <div class="row">
      <div class="col-lg-12 text-center">        <?php print render($title_prefix); ?>
        <h2 class="section-heading"><?php print $block->subject ?></h2>
        <?php print render($title_suffix); ?>
        <h3 class="section-subheading text-muted">Lorem ipsum dolor sit amet consectetur.</h3>
      </div>
    </div>

    <div class="row text-center">
      <?php print $content ?>
    </div>

  </div>
</section>
