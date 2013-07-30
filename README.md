API-Tokens
==========

The API Tokens module provides an input filter that allows to replace custom parametric tokens with rendered
content. Each module is able to define own parametric tokens (via hook_api_tokens_info) and token render
function. Module provides flexible caching mechanism.
<br/>
Examples<br/>
  Token:  [api:date/]<br/>
  Result: <strong>07-Mar-13</strong><br/>
<br/>
See <a href="https://github.com/azhulin/api-tokens/blob/master/api_tokens/api_tokens.api.php">API</a> for more details.
