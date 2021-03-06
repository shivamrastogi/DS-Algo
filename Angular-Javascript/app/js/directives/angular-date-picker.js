  'use strict';

aangular.module('angularBaseUiApp')
.directive('angularDatePicker', ['templateURL', function(templateURL) {
  return {
    controller : ['$scope','$timeout','$element',function($scope,$timeout,$element){
      var options = {
        maxYear : new Date().getFullYear(), 
        yearRange : 120,
        dateFormat: "dd/mm/yy"
      };
      var _imageOptions = {
         inline : true,
         showOn: 'focus',
         showButtonPanel: true,
         closeText: 'Clear'
      }
      $timeout(function(){
        options = angular.extend(options, $scope.dateOptions);
        options = angular.extend(options, _imageOptions);

      },0);
      this.initDatePicker = function(mandatoryOptions){
          $timeout(function(){
              options = angular.extend(options,mandatoryOptions);
              $element.datepicker(options);
            },0);
        }
    }],
    replace: false,
    require : ['ngModel','angularDatePicker'],
    scope : {
      name : '@',
      id: '@',
      disabled : '=ngDisabled',
      dateOptions : '=angularDateOptions'
    },
    compile : function($element,$attrs){
            return {
                post : function(scope,element,attrs,controllers){
                    var ngModelCtrl = controllers[0],
                    angularDatePickerCtrl = controllers[1];
                    var updateModal = function(dateText){
                             ngModelCtrl.$setViewValue(dateText);
                      };
                        var mandatoryOptions = {
                          changeYear : true,
                          changeMonth : true,
                          onSelect : function(dateText){
                                updateModal(dateText);
                          },
                         onClose: function (dateText) {
                                if ($(window.event.srcElement).hasClass('ui-datepicker-close')) {
                                  $(this).val('');
                                  updateModal(null);
                                }
                          }
                        };
                    angularDatePickerCtrl.initDatePicker(mandatoryOptions);
                }
            }
    },

  }
}]);