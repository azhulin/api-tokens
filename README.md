API-Tokens
==========

This module defines an input filter that allows to process API tokens.
Supports flexible caching mechanisms.
Any module is able to provide own tokens via hook_api_tokens_info().

Examples
  Token:  [api:date/]
  Result: <strong>07-Mar-13</strong>

  Token:  [api:link["Drupal", "http://drupal.org", {"attributes": {"target": "_blank", "class": ["button"]}}]/]
  Result: <a class="button" target="_blank" href="http://drupal.org">Drupal</a>
