/**
 * @file
 */
(function ($) {

  // Add classes to team member images to make them round and reponsive.
  Drupal.behaviors.agencyImageClasses = {
    attach: function (context) {

      $('#team').find('.team-member').find('img').each(function() {
        $(this).addClass('img-responsive').addClass('img-circle');
      });

      $('#portfolio').find('.portfolio-item').find('img').each(function() {
        $(this).addClass('img-responsive');
      });

      $('#about').find('.timeline-image').find('img').each(function() {
        $(this).addClass('img-responsive').addClass('img-circle');
      });

    }
  };

})(jQuery);
