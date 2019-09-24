/*
 * Translated default messages for the jQuery validation plugin.
 * Locale: KO
 */
jQuery.extend(jQuery.validator.messages, {
		required		: " 반드시 입력(선택)하셔야 합니다.",
		remote			: " Please fix this field.",
		email			: " 이메일 주소가 올바르지 않습니다.",
		url				: " URL 주소가 올바르지 않습니다.",
		date			: " 날자 형식이 올바르지 않습니다.",
		dateISO			: " 날자 형식이 올바르지 않습니다. (ISO).",
		number			: " 숫자형식으로 입력해주시기 바랍니다.",
		digits			: " 정수형식으로 입력해주시기 바랍니다.",
		creditcard		: " 신용카드 형식으로 입력해주시기 바랍니다.",
		equalTo			: " 동일한 값을 입력해주시기 바랍니다.",
		accept			: " Please enter a value with a valid extension.",
		maxlength		: $.validator.format(" {0}글자 이상 입력하실수 없습니다."),
		minlength		: $.validator.format(" {0}글자 이상 입력해주시기 바랍니다."),
		rangelength		: $.validator.format(" Please enter a value between {0} and {1} characters long."),
		range			: $.validator.format(" Please enter a value between {0} and {1}."),
		max				: $.validator.format(" {0} 이하의 값을 입력해주시기 바랍니다."),
		min				: $.validator.format(" {0} 이상의 값을 입력해주시기 바랍니다.")
});

/* 경고창으로 띄우기 */
jQuery.validator.setDefaults({
	onkeyup:false,
	onclick:false,
	onfocusout:false,
	showErrors:function(errorMap, errorList){
		if($(errorList).length > 0)
		{		  
			var caption = $(errorList[0].element).attr('placeholder') || $(errorList[0].element).attr('alt') || $(errorList[0].element).attr('name');
			alert('[' + caption + ']' + errorList[0].message);
		}
	}
});
/*
$.validator.addMethod("password", function( value, element ) {
	var result = this.optional(element) || value.length >= 6 && /\d/.test(value) && /[a-z]/i.test(value);
	if (!result) {
		element.value = "";
		var validator = this;
		setTimeout(function() {
			validator.blockFocusCleanup = true;
			element.focus();
			validator.blockFocusCleanup = false;
		}, 1);
	}
	return result;
}, "비밀번호는 최소 6자리 숫자, 알파벳 혼합으로 입력하셔야 합니다.");
*/
$.validator.addMethod("userid", function( value, element ) {
	var result = this.optional(element) || /[a-z0-9_]{4,12}/i.test(value);
	if (!result) {
		element.value = "";
		var validator = this;
		setTimeout(function() {
			validator.blockFocusCleanup = true;
			element.focus();
			validator.blockFocusCleanup = false;
		}, 1);
	}
	return result;
}, "아이디는 4~12자 숫자, 영문으로만 입력 가능합니다.");