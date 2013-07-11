Previous/Next Node ID API
=========================

This module provides a function that retrives the previous and/or next Node ID
in a sequence as defined in a list of options passed as a param to the function
sorted by Node ID, Node Title, Published or Changed date. The queries used to
generate this sequence can be slow so this module also creates a table for
storage and quick retrieval of the values.

Sequences can be restricted by node status, node type and taxonomy terms.

USAGE
-----

The following function is available after enabling the module:

    pn_nid($nid, $op = 'next', $sort = SORT_NID, $options = array('types' => FALSE, 'terms' => FALSE, 'unpublished' => FALSE))

###Examples###

Return the next published node after Node ID 100 of any content type:

    pn_nid(100);
    // Returns `101` If nid 101 exists and is published.

Return the previous published node before Node 100 of any content type:

    pn_nid(100, 'prev');
    // Returns `99` If nid 99 exists and is published.

Return the next node ofter Node ID 100 that is published and an `article` or
`page` content type:

    pn_nid(100, 'next', SORT_NID, array('types' => array('article', 'page')));
    // Returns `101` If nid 101 exists, is published and is either a page or
    // article.

Return the next node after Node ID 100 that is an `article` or `page` content
type regardless of whether or not it is published:

    pn_nid(100, 'next', SORT_NID array('types' => array('article', 'page'), 'unpublished' => TRUE));

Return the next node after Node 100 sorted alphabetically.

    pn_nid(100, 'next', SORT_ALPHA);

SORTING
-------

The third parameter controls how the sequence is sorted and accepts one of the
following named constants:

* **SORT_NID** (default)
  > Sorts the results numerically based on Node ID

* **SORT_ALPHA**
  > Sorts the results alphabetically based on Node Titles

* **SORT_CREATED**
  > Sorts the results based on Node creation dates

* **SORT_CHANGED**
  > Sorts the results based on Node last updated dates

DATABASE STORAGE
----------------

By default, the Previous/Next cache is cleared each time a node is created/
saved/deleted. This is appropriate for most sites because doing so can affect
the next or previous node in a given sequence.

You can also choose to have the cache emptied on cron or turn off automatic
cache clearing entirely.


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

4. This module allows you to set the sort criteria. Previous/Next API only
   allows you to sort by Node ID (arguably the least valuable option).

