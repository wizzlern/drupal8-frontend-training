(function ($) {

  // Add classes to team member images to make them round and reponsive.
  Drupal.behaviors.agencyImageClasses = {
    attach: function (context) {
      $('#team').find('.team-member').find('img').each(addImageClasses);
      $('#about').find('.timeline-image').find('img').each(addImageClasses);
    }
  };

  var addImageClasses = function () {
    $(this).addClass('img-responsive').addClass('img-circle');
  };

})(jQuery);