API-Tokens
==========

This module defines an input filter that allows to process API tokens.<br/>
Supports flexible caching mechanisms.<br/>
Any module is able to provide own tokens via hook_api_tokens_info().<br/>
<br/>
Examples<br/>
  Token:  [api:date/]<br/>
  Result: <strong>07-Mar-13</strong><br/>
<br/>
  Token:  [api:link["Drupal", "http://drupal.org", {"attributes": {"target": "_blank", "class": ["button"]}}]/]<br/>
  Result: <a class="button" target="_blank" href="http://drupal.org">Drupal</a>
