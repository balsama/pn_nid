Previous/Next Node ID API
=========================

This module provides a function that retrives the previous and/or next Node ID
in a sequence as defined in a list of options passed as a param to the
function. The queries used to generate this sequence can be slow so this module
also creates a table for storage and quick retrieval of the values.

Sequences can be restricted by node status, node type and taxonomy terms.

USAGE
-----

The following function is available after enabling the module:

    pn_nid_query($nid, $op = 'next', $options = array('types' => FALSE, 'terms' => FALSE, 'unpublished' => FALSE))

###Examples###

Return the next published node after Node ID 100 of any content type:

    pn_nid_query(100);
    // Returns `101` If nid 101 exists and is published.

Return the previous published node before Node 100 of any content type:

    pn_nid_query(100, 'prev');
    // Returns `99` If nid 99 exists and is published.

Return the next node ofter Node ID 100 that is published and an `article` or
`page` content type:

    pn_nid_query(100, 'next', array('types' => array('article', 'page')));
    // Returns `101` If nid 101 exists, is published and is either a page or
    article.

Return the next node ofter Node ID 100 that is an `article` or `page` content
type regardless of whether or not it is published:

    pn_nid_query(100, 'next', array('types' => array('article', 'page'), 'unpublished' => TRUE))

DATABASE STORAGE
----------------

By default, the Previous/Next values in the database are cleared on cron. You
can turn this setting off by visiting the admin page. Values are generated and
stored the first time they are requested after the table is cleared.

You can also manually empty the Previous/Next values on the admin page.

If you would like more granular control over when the values are cleared, use
a module like [Elysia Cron](https://drupal.org/project/elysia_cron) to set
fine-grained control.

SIMILAR MODULES
---------------

[Previous/Next API](https://drupal.org/project/prev_next) provides similar
functionality, but differs from this module in the following significant ways:

1. Previous/Next API builds the entire Previous/Next Node table on cron (or in
   batches of 200 nodes at a time) whereas this module doesn't create an entry
   until that specific Previous/Next sequence is requested.

2. Previous/Next API limits the administrator to one set of node types to
   reuturn. This module allows you to, for example, have a link to the next
   node of Content Type A in one template, and a link to the next node of
   Content Type B on another.

3. This module allows you to limit Previous/Next results by Taxonomy.

